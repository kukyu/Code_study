# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://docs.scrapy.org/en/latest/topics/item-pipeline.html


# useful for handling different item types with a single interface
# from itemadapter import ItemAdapter
# import pandas as pd

# class St02Pipeline:
#     def process_item(self, item, spider):
#         shopName = item["shopName"]
#         data = pd.DataFrame({'店名':shopName})
#         data.to_csv(".\店铺信息3.csv", index = False, header=0, mode='a', encoding='ANSI')
#         return item
    

#     def process_item(self, item, spider):
#         shopAddr = item["shopAddr"]
#         route = item["route"]
#         data = pd.DataFrame({'地址':shopAddr, '路线':route})
#         data.to_excel(".\店铺信息1.xlsx", index=False)
#         return item

# 下载图片 管道类
from scrapy.pipelines.images import ImagesPipeline
import scrapy
class imagesPipeline(ImagesPipeline):
    # 将图片的url请求发送
    def get_media_requests(self, item, info):
        yield scrapy.Request(item['picturesLink'])
    # 定义图片名称，图片存储目录到settings.py中设置
    def file_path(self, request, response=None, info=None):
        picName = request.url.split('/')[-1]
        return picName
    # 可以省略，返回下一个管道
    def item_completed(self, results, item, info):
        return item

    
