import requests
from pypinyin import lazy_pinyin
from lxml import etree


# cityName = input("请输入城市名称：")
cityName = '武汉'
ret = lazy_pinyin(cityName, style=0)
# print(ret)
cityName = ''.join(ret)
# print(ret)
link = f"https://www.tianqi.com/{cityName}/"
uaAgent = {
            'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36'}
requestData = requests.get(url=link, headers=uaAgent).text
dataGet = etree.HTML(requestData)
cityName = dataGet.xpath('//dd[@class="name"]/h1/text()')[0]
# print(cityName)
todayDate = dataGet.xpath('//dd[@class="week"]/text()')[0]
# print(todayDate)
weather = dataGet.xpath('//dd[@class="weather"]/span/b/text()')[0]
# print(weather)
todayTemperature = dataGet.xpath('//dd[@class="weather"]/span/text()')[0]
# print(todayTemperature)
nowTemperature = dataGet.xpath('//p[@class="now"]/b/text()')[0]
# print(nowTemperature)
otherInfo = dataGet.xpath('//dd[@class="shidu"]//b/text()')
otherInfo = ",".join(otherInfo)
# print(otherInfo)
airQuality = dataGet.xpath('//dd[@class="kongqi"]/h5/text()')[0]
# print(airQuality)
PM = dataGet.xpath('//dd[@class="kongqi"]/h6/text()')[0]
PM = PM.split(":")[-1]
PM = PM.strip()
# print(PM)
sunriseAndSunset = dataGet.xpath('//dd[@class="kongqi"]/span/text()')
sunriseAndSunset = ",".join(sunriseAndSunset)
# print(sunriseAndSunset)
print(cityName,todayDate)
print(f"天气：{weather}, 现在温度：{nowTemperature}℃, 全天温度：{todayTemperature}")
print(otherInfo)
print(f"空气质量PM2.5: {PM}")
print(f"日出日落：{sunriseAndSunset}")