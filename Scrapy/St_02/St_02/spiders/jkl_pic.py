import scrapy
from St_02.items import St02Item

class JklPicSpider(scrapy.Spider):
    name = "jkl_pic"
    # allowed_domains = ["www.kukyu.com"]
    start_urls = ["https://www.jkl.com.cn/phoLis.aspx"]

    def parse(self, response):
        picturesLink = response.xpath('//div[@class = "proLis"]//@src').extract()
        # print(picturesLink)
        # picturesLink = ["http://www.jkl.com.cn" + i for i in picturesLink]
        for i in picturesLink:
            picturesLink = "http://www.jkl.com.cn" + i
            # print(picturesLink)
            item = St02Item()
            item["picturesLink"] = picturesLink
            yield item
            
        
