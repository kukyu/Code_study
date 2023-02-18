#  await + 可等待的对象（协程对象，Task对象，Future对象）
import asyncio

async def fun2():  # 协程函数
    print("我是第一个插队的")
async def fun3():  # 协程函数
    print("我是第二个插队的")
async def fun():  # 协程函数
    print("第一个执行的任务")
    requestData = await fun2()
    requestData = await fun3()
    print("结束了",requestData)
asyncio.run(fun())  #协程函数的使用








