import scrapy
from St_02.items import St02Item

class JklSpider(scrapy.Spider):
    name = "jkl"
    # allowed_domains = ["www.kykyu.com"]
    start_urls = ["https://www.jkl.com.cn/shop.aspx"]
    
    def NextAnalysis(self, dataGet1): # 下一页解析
        shopName = dataGet1.xpath('//span[@class = "con01"]/text()').extract() 
        # print(shopName)
        # shopAddr = dataGet1.xpath('//span[@class = "con02"]/text()').extract()  # 地址
        # shopTel = dataGet1.xpath('//span[@class = "con03"]/text()').extract()   # 电话
        # shopTime = dataGet1.xpath('//span[@class = "con04"]/text()').extract()   # 营业时间
        shopName = [name.strip() for name in shopName]
        # print(shopName)

        # 实例化
        item = St02Item()
        item["shopName"] = shopName
        # print(item["shopName"])

        # 交给管道空间
        yield item



    def parse(self, response):
        # pass
        # print(response)
        cityArea = response.xpath('//div[@class="infoLis"]//@href').extract()
        # print(cityArea)
        for area in cityArea:
            link = 'https://www.jkl.com.cn/' + area
            # print(link)
            yield scrapy.Request(url=link, callback=self.NextAnalysis)


    
