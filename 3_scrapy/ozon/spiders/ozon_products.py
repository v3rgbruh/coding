import json
from scrapy import Spider
from scrapy.crawler import CrawlerProcess
from scrapy.utils.log import configure_logging
from scrapy.utils.project import get_project_settings as settings


class OzonProductsSpider(Spider):
    name = 'ozon_items'

    start_urls = [
        'https://www.ozon.ru/api/composer-api.bx/page/json/v2?url=/product/smartfon-apple-iphone-12-64-gb-belyy-191319105/?layout_container=pdpPage2column&layout_page_index=2']
    custom_settings = {'DOWNLOADER_MIDDLEWARES': {'ozon.middlewares.ProductsMiddleWare': 491}}

    def __init__(self):
        for i, url in enumerate(self.start_urls):
            if url[0] == '/':
                self.start_urls[i] = settings()['API_URL'] + url + settings()['API_PARAMS']
        super().__init__()

    def parse(self, response):
        if self.is_banned(response):
            print('me banned')
            return

        os_name = ''
        os_ver = ''
        start = response.text.find('{')
        end = response.text.rfind('}')

        json_extracted = json.loads(response.text[start:end + 1])
        for item, value in json_extracted['widgetStates'].items():
            if 'webCharacteristics' in item:
                for key in json.loads(value)['characteristics']:
                    for c in key['short']:
                        os_name = c['key'] == 'OSWithoutVer' and c['values'][0]['text'] or os_name
                        os_ver = c['key'] in ['AndroidVersion', 'iOSVer'] and c['values'][0]['text'] or os_ver
        yield {"os_name": os_name,
               "os_ver": os_ver}

    @staticmethod
    def is_banned(response):
        return response.css('title::text').get() in ['Just a moment...',
                                                     'Access denied | www.ozon.ru used Cloudflare to restrict access']


def crawl(urls):
    OzonProductsSpider.start_urls = urls
    configure_logging()
    process = CrawlerProcess(settings())
    process.crawl(OzonProductsSpider)
    process.start()
