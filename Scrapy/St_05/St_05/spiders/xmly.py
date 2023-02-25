# 网页改版 爬取出问题暂停


import scrapy
from scrapy.linkextractors import LinkExtractor
from scrapy.spiders import CrawlSpider, Rule


class XmlySpider(CrawlSpider):
    name = "xmly"
    # allowed_domains = ["wwww.com"]
    start_urls = ["https://www.ximalaya.com/album/6233693/"]

    rules = (Rule(LinkExtractor(allow=r"6233693/p\d+/"), callback="parse_item", follow=True),)

    def parse_item(self, response):
        print(response)
        # item = {}
        #item["domain_id"] = response.xpath('//input[@id="sid"]/@value').get()
        #item["name"] = response.xpath('//div[@id="name"]').get()
        #item["description"] = response.xpath('//div[@id="description"]').get()
        # return item
