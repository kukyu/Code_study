# Define here the models for your scraped items
#
# See documentation in:
# https://docs.scrapy.org/en/latest/topics/items.html

import scrapy

class St02Item(scrapy.Item):
    # define the fields for your item here like:
    # name = scrapy.Field()
    # pass
    shopName = scrapy.Field()
    route = scrapy.Field()
    shopAddr = scrapy.Field()
    picturesLink = scrapy.Field()
    