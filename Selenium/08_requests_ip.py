import requests
proxies = {
    'http': 'http://210.5.10.87:53281',
    'http': 'http://117.94.120.236:9000',
    'http': 'http://121.13.252.58:41564'
}
UA伪装 = {'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36'}
响应数据 = requests.get(url='http://www.4399.com/',headers=UA伪装,proxies=proxies).text
print(响应数据)

# 网络上的代理都是这一秒可以下一秒不行了，你只能靠靠运气用用网上的 IP
