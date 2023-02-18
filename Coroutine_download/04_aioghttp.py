import requests
import asyncio
import aiohttp

async def 下载文件(网址):
    print("开始下载",网址)
    文件名 = 网址.split("/")[-1]
    async with aiohttp.ClientSession() as session:
        # 发POST请求时用session.post
        # headers,params/data,proxy='http://ip:port'
        async with await session.get(url=网址) as 响应对象:
            # text()方法：相当于requests中的text属性
            # read()方法: 相当于requests中的content属性
            # json()方法
            # 获取响应数据操作之前要await手动挂起
            响应数据 = await 响应对象.read()
            with open(f'./Coroutine_download/Doc/{文件名}','wb') as 变量名:
                变量名.write(响应数据)
            print(f"下载完成, {网址}")
列表 = [
    'http://www.jkl.com.cn/UserFiles/16-17292190424.pdf',
    'http://www.jkl.com.cn/UserFiles/17-17293434387.pdf',
    'http://www.jkl.com.cn/UserFiles/18-17295063715.pdf'
]
task对象 = [下载文件(网址) for 网址 in 列表]
asyncio.run(asyncio.wait(task对象))