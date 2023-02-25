import scrapy


class NovelSpider(scrapy.Spider):
    name = "novel"
    # allowed_domains = ["www.biqugeg.cc"]
    start_urls = [
        "https://www.23sk.net/files/article/html/72/72626/157518.html"]

    def parse(self, response):
        # print(response)
        chapterName = response.xpath(
            '//div[@class="bookname"]/h1/text()').extract()[0]
        # print(chapterName)
        content = response.xpath('//div[@id="content"]//text()').extract()
        content = "".join(content)
        content = content.replace("\u3000\u3000", "\n")
        
        # # print(content)
        item = {"chapterName": chapterName, "content": content}
        # print(item)
        yield item
        nextPage = response.xpath('//div[@class="bottem2"]/a[4]/@href').extract_first()
        # print(nextPage)
        # nextPage = "https://www.23sk.net/" + nextPage
        if ".html" in nextPage:
            nextPage = response.urljoin(nextPage) # 智能拼接网址
            print(nextPage)
            yield scrapy.Request(nextPage, callback=self.parse)