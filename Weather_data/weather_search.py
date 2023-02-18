import requests
from pypinyin import lazy_pinyin
from lxml import etree

while True:
    print("---------------------------------------------")
    print("欢迎查询天气！")
    cityName = input("请输入城市名称：")
    # cityName = '武汉'
    ret = lazy_pinyin(cityName, style=0)
    # print(ret)
    cityNameEn = ''.join(ret)
    # print(ret)
    link = f"https://www.tianqi.com/{cityNameEn}/"
    uaAgent = {
                'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36'}
    requestData = requests.get(url=link, headers=uaAgent).text
    dataGet = etree.HTML(requestData)
    cityName = dataGet.xpath('//dd[@class="name"]/h1/text()')[0]
    cityName = cityName.replace("天气","")
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
    print("---------------------------------------------")
    print(f"{cityName}的今天天气如下：\n")

    print(cityName,todayDate)
    print(f"天气：{weather}, 现在温度：{nowTemperature}℃, 全天温度：{todayTemperature}")
    print(otherInfo)
    print(f"空气质量PM2.5: {PM}")
    print(f"日出日落：{sunriseAndSunset}")
    print("---------------------------------------------")
    ret = input(f"是否继续查询{cityName}多天天气预报？是(y)：")
    if ret == "是" or ret == "Y" or ret == 'y':
        while True:
            day = input("只能查询3天，7天，10天， 15天，30天，40天，请输入查询天数：")
            if day in ['3', '7', '10', '15', '30', "40"]:
                link = f"https://www.tianqi.com/{cityNameEn}/{day}/"
                # print(link)
                requestData = requests.get(url=link, headers=uaAgent).text
                dataGet = etree.HTML(requestData)
                date = dataGet.xpath('//div[@class="weaul_q weaul_qblue"]/span/text()')
                date = [date.strip() for date in date]
                date = [''.join(date[i : i+2])  for i in range(0, len(date), 2)]
                # print(date)
                date2 =  dataGet.xpath('//div[@class="weaul_q"]/span/text()')
                date2 = [date2.strip() for date2 in date2]
                date2 = [''.join(date2[i : i+2])  for i in range(0, len(date2), 2)]
                # print(date2)
                date = date + date2
                weather = dataGet.xpath('//div[@class="weaul_z"]//text()')
                weather = [weather[i] + "," + ''.join(weather[i+1 : i+5])  for i in range(0, len(weather), 5)]
                # print(weather)
                print("---------------------------------------------")
                print(f"{cityName}的近{day}天天气如下：\n")
                for i in range(len(date)):
                    print(f"{date[i]},{weather[i]}")
                break
            else:
                print("输入错误，请重新输入！")
    print("---------------------------------------------")
    ret = input("输入否(n)退出程序，否则继续查询天气，请输入：")
    # print("---------------------------------------------")
    if ret == "否" or ret == "n" or ret == 'N':
        break

    