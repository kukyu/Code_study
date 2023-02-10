import requests
import json
import os
import time

uaAgent = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.3',
           'Referer': 'http://www.kuwo.cn/search/list?key=%E5%91%A8%E6%9D%B0%E4%BC%A6',
           'csrf': 'RUJ53PGJ4ZD',
           'Cookie': 'Hm_lvt_cdb524f42f0ce19b169a8071123a4797=1577029678,1577034191,1577034210,1577076651; Hm_lpvt_cdb524f42f0ce19b169a8071123a4797=1577080777; kw_token=RUJ53PGJ4ZD'
           }

singerName = input("请输入要下载的歌手：")
# singerName = "小阿七"
page = int(input("请输入要下载的页数："))
# page = 2

filePath = f"./Kuwo_music/{singerName}"
if not os.path.exists(filePath):
    os.mkdir(filePath)
for i in range(1, page+1):
    link = f"https://www.kuwo.cn/api/www/search/searchMusicBykeyWord?key={singerName}&pn={i}&rn=20&httpsStatus=1&reqId=a0a33211-a8ff-11ed-b5f5-33cbc2c7b1ab"

    requestData = requests.get(url=link, headers=uaAgent).text
    dict1 = json.loads(requestData)
    # print(dict1)
    list1 = dict1['data']['list']
    for i in list1:
        # print(i)
        rid = i['rid']
        songName = i['name']
        # print(rid, name)
        link = f"https://www.kuwo.cn/api/v1/www/music/playUrl?mid={rid}&type=music&httpsStatus=1&reqId=178128d0-a903-11ed-b1af-9d82c033fea0"
        requestData = requests.get(url=link, headers=uaAgent).text
        dict1 = json.loads(requestData)
        # print(dict1)
        if dict1['code'] == 200:
            downLink = dict1['data']['url']
            # print(downLink)
            mp3 = requests.get(url=downLink).content
            downAddr = filePath + "/" + f"{songName}.mp3"
            # print(downAddr)
            with open(downAddr, 'wb') as w:
                w.write(mp3)
                print(songName, "下载成功！")
        time.sleep(10)
