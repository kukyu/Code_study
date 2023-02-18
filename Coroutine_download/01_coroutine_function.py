
import asyncio


async def fun():  # 协程函数
    print("test")
coroutineObj = fun()
asyncio.run(coroutineObj)  #协程函数的使用






