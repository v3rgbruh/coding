from scrapy.crawler import CrawlerProcess
from scrapy.utils.project import get_project_settings as settings
from concurrent.futures import ProcessPoolExecutor
from ozon.spiders.ozon_products import crawl
import json
import pandas as pd
import os


def get_user_urls(file: str = 'tmp/links.txt'):
    with open(file) as file:
        url_list = []
        for line in file:
            url_list.append(line)
            if len(url_list) == settings()["MAX_URLS"] / settings()['MAX_SPIDERS']:
                yield url_list
                url_list = []
        if len(url_list) > 0:
            yield url_list


def crawl_concurrency():
    urls = get_user_urls()
    with ProcessPoolExecutor() as executor:
        executor.map(crawl, urls)


def get_results():
    vals = []
    with open('tmp/os.txt', 'r') as file:
        vals.extend([json.loads(line) for line in file.readlines()])
    df = pd.DataFrame.from_records(vals)
    df = df.value_counts('os_ver')
    df.to_csv('results.csv')


def banner(act):
    print('\n')
    print('#' * 50)
    print(act)
    print('#' * 50)


if __name__ == "__main__":
    # 0. Preparing proxies
    os.system('docker-compose up -d')

    # 1. Grab 100 links
    banner('Preparing links ...')
    p = CrawlerProcess(settings())
    p.crawl('ozon_category')
    p.start()

    # 2. Open links using api and grab json info
    # Feed 100 links into small chunks with own proxies and separate processes
    banner('Grabbing products information ...')
    try:
        os.remove('tmp/os.txt')
    except (BaseException,):
        pass
    crawl_concurrency()

    # 3. Save results sorted to output files
    try:
        get_results()
        banner('Saving results ...')
    except (BaseException, FileNotFoundError):
        print("Step two was failed, probably cloudflare ban")

