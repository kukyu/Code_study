# 网址中的其他网址 meta传参
import scrapy
from St_02.items import St02Item

class Jkl2Spider(scrapy.Spider):
    name = "jkl_2"
    # allowed_domains = ["www.kykyu.com"]
    start_urls = ["https://www.jkl.com.cn/shopLis.aspx?TypeId=10046"]

    def parse(self, response):
        item = St02Item()
        shopAddr = response.xpath(
            '//span[@class = "con02"]/text()').extract()[0]  # 地址
    #    print(shopAddr)
        url = response.xpath('//div[@class="shopLis"]//a/@href').extract()[0]
        # print(url)
        url = "https://www.jkl.com.cn/" + url
        item["shopAddr"] = shopAddr
        yield scrapy.Request(url=url, callback=self.NextAnalysis, meta={'item':item})

    def NextAnalysis(self, response):
        item = response.meta['item']
        route = response.xpath('//div[@class = "text"]/p[2]/text()').extract()
        # print(route)
        item['route'] = route
        yield item



