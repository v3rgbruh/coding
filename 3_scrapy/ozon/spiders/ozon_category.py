from scrapy import Spider
from scrapy.exceptions import CloseSpider
from scrapy.utils.project import get_project_settings as settings


class OzonCategorySpider(Spider):
    name = 'ozon_category'

    start_urls = [f'{settings()["BASE_URL"]}/category/smartfony-15502/?sorting=rating']
    custom_settings = {'DOWNLOADER_MIDDLEWARES': {'ozon.middlewares.CategoriesMiddleWare': 491}}
    urls = []

    def parse(self, response):
        def check_stop_grabbing():
            if len(self.urls) >= settings()["MAX_URLS"]:
                print('saving...')
                self.urls = self.urls[:settings()["MAX_URLS"]]
                self.save_urls()
                raise CloseSpider('finished')

        try:
            # Advertisement products filtering
            products = response.xpath('//*[@data-widget="searchResultsV2"]/div/div[not(@style)]')
            for product in products:
                check_stop_grabbing()
                url = product.css('a::attr("href")').get().split('?')[0]
                self.urls.append(url)
        except CloseSpider:
            pass
        except (BaseException,):
            print('can\'t find products')

        print(f'{len(self.urls)} urls')
        check_stop_grabbing()
        try:
            next_page = response.xpath('//*[@data-widget="megaPaginator"]/div//./a/@href')[-1].get().split('&')[0]
            if next_page is not None:
                yield response.follow(response.urljoin(next_page))
        except (BaseException,):
            print('can\'t find next page')

    def save_urls(self):
        with open('tmp/links.txt', 'w') as file:
            for url in self.urls:
                file.write(url + '\n')
        print('100 product links was saved to links.txt file')
