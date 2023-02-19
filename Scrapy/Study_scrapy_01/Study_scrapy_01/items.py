# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy


class StudyScrapy01Item(scrapy.Item):
    # define the fields for your item here like:
    # name = scrapy.Field()
    shopName = scrapy.Field()
    shopAddr = scrapy.Field()
    shopTel = scrapy.Field()
    shopTime = scrapy.Field()
    # pass
