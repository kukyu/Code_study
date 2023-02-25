import scrapy
from Study_scrapy_01.items import StudyScrapy01Item


class Number1Spider(scrapy.Spider):
    name = "number_1"
    # allowed_domains = ["www.kukyu.com"]
    start_urls = ["https://jkl.com.cn/shopLis.aspx?TypeId=10045"]

    def parse(self, response):
        # shopName = response.xpath(
        #     '//span[@class="con01"]/text()').extract()[0]  # 第一个数据
        shopName = response.xpath(
            '//span[@class="con01"]/text()').extract() 
        shopAddr = response.xpath(
            '//span[@class="con02"]/text()').extract()  
        # shopAddr = response.xpath(
        #     '//span[@class="con02"]/text()').extract_first()  # 第一个数据
        # print(shopAddr)
        shopTime = response.xpath(
            '//span[@class="con04"]/text()').extract()  # 第一个数据
        # print(shopTime)
        shopTel = response.xpath(
            '//span[@class="con03"]/text()').extract()  # 第一个数据
        # print(shopTel)
        print(f"{shopName}\n{shopAddr}\n{shopTel}\n{shopTime}")

        item = StudyScrapy01Item()  # 实例化对象 

        # 封装存储
        item['shopName'] = shopName
        item['shopAddr'] = shopAddr
        item['shopTel'] = shopTel
        item['shopTime'] = shopTime

        # 将item提交给管道
        return item


