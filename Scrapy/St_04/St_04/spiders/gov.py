import scrapy


class GovSpider(scrapy.Spider):
    name = "gov"
    allowed_domains = ["www.kk"]
    start_urls = ["http://mzj.wuhan.gov.cn/zwgk_918/fdzdgk/qtzdgknr/rsxx/"]

    def parse(self, response):
        # print(response)
        ulList = response.xpath('//div[@class="article-box"]/ul/li')
        # print(ulList[0])
        for ul in ulList:
            title = ul.xpath("./a/@title").extract_first()
            # print(title)
            url = ul.xpath("./a/@href").extract_first()
            # print(url)
            url = response.urljoin(url) # 智能拼接网址
            # print(url)
            # print(title, url)
            item = {"title":title, "url":url}  # 取文字可不在item设置
            yield scrapy.Request(item["url"], callback=self.NextPageInfo, meta={"item":item})
        nextPage = response.xpath('//a[text()=" 下一页"]/@href').extract_first()
        if nextPage is not None:
            yield scrapy.Request(nextPage,callback=self.parse)
    def NextPageInfo(self, response):
        item = response.meta("item")  # 接收item
        text = response.xpath()
        pass
        # 找不到下载和文本链接


