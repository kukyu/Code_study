import requests
import pandas as pd
import json
import time

print("=======如果退出，请输入0，并按回车=======")
while(True):
    myInput = input("请输入翻译的文字:")
    # myInput = "你好"
    if(myInput ==  '0'):
        break
    else:
        uaAgent = {
            'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36'}
        link = "http://fanyi.youdao.com/translate?smartresult=dict&smartresult=rule"
        requestData = requests.get(url=link, headers=uaAgent).text
        # print(requestData)
        data ={}
        data['i'] = myInput
        data['doctype'] = "json"
        data['from'] = "AUTO"
        data['to'] = " "
        data['client'] = "fanyideskweb" 
        # print(data)
        requestData = requests.post(url=link,headers=uaAgent, data=data).text
        # print(requestData)
        dict1 = json.loads(requestData)  # 字符串类型 但是字典,json使之变成字典
        # print(type(dict1))
        transRes = dict1["translateResult"][0][0]['tgt']
        # print(dict1["translateResult"][0][0]['tgt'])
        data = pd.DataFrame({"输入":[myInput], "翻译结果":[transRes]})
        data.to_csv("./Youdao_dict/翻译结果.csv", index=False, header=0, mode="a", encoding="ANSI")
        time.sleep(3)
        


