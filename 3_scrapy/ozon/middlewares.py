from random import choice, random
from time import sleep
from scrapy.http import HtmlResponse
from scrapy.signals import spider_closed
from scrapy.signalmanager import SignalManager, dispatcher
from scrapy.utils.project import get_project_settings as settings
from undetected_chromedriver import Chrome, ChromeOptions


class CategoriesMiddleWare:
    def __init__(self):
        options = ChromeOptions()
        options.add_argument('--headless')
        self.driver = Chrome(driver_executable_path="chromedriver", options=options)
        SignalManager(dispatcher.Any).connect(self.spider_closed, signal=spider_closed)

    def process_request(self, request, spider):
        self.driver.get(request.url)
        sleep(4)
        return HtmlResponse(request.url, encoding='utf-8', body=self.driver.page_source, request=request)

    def process_response(self, request, response, spider):
        return response

    def spider_closed(self, spider):
        if self.driver:
            self.driver.close()
            self.driver.quit()
            self.driver = None


class ProductsMiddleWare(CategoriesMiddleWare):
    def __init__(self):
        options = ChromeOptions()
        options.headless = True
        # options.add_argument('start-maximizied')
        options.add_argument(f'--user-agent="{choice(settings()["UA_LIST"])}"')
        options.add_argument(f'--proxy-server={choice(settings()["PROXY_LIST"])}')
        # options.add_argument(f'--proxy-server={PROXY_LIST[0]}')
        self.driver = Chrome(executable_path="chromedriver", options=options)

        SignalManager(dispatcher.Any).connect(self.spider_closed, signal=spider_closed)

    def process_request(self, request, spider):
        self.driver.get(request.url)
        sleep(min(3.0, 5 * random()))
        return HtmlResponse(request.url, encoding='utf-8', body=self.driver.page_source, request=request)
