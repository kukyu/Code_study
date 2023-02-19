# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://docs.scrapy.org/en/latest/topics/item-pipeline.html


# useful for handling different item types with a single interface
from itemadapter import ItemAdapter
import pandas as pd
import pymysql

class StudyScrapy01Pipeline:
    # 接收爬虫文件传过来的item对象
    def process_item(self, item, spider):
        shopName = item['shopName']
        shopAddr = item['shopAddr']
        shopTel = item['shopTel']
        shopTime = item['shopTime']
        data = pd.DataFrame({"店铺名称":shopName,"店铺地址":shopAddr,"电话":shopTel,"营业时间":shopTime})
        data.to_excel("./Study_scrapy_01/Doc_save/店铺信息.xlsx", index=False)
        return item

# class SaveMysql():
#     # 接收爬虫文件传过来的item对象
#     def process_item(self, item, spider):
#         shopName = item['shopName']
#         shopAddr = item['shopAddr']
#         shopTel = item['shopTel']
#         shopTime = item['shopTime']
#         data = pd.DataFrame({"店铺名称":shopName,"店铺地址":shopAddr,"电话":shopTel,"营业时间":shopTime})
#         data.to_excel("./Study_scrapy_01/Doc_save/店铺信息.xlsx", index=False)
#         return item
