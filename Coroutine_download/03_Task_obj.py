# Task对象作用：帮助你在事件循环中添加多个任务。
# Task对象创建：asyncio.create_task(协程对象)

import asyncio
async def func1():
    print("康熙")
    await asyncio.sleep(2)
    print("乾隆")
async def func2():
    print("叶问")
    await asyncio.sleep(2)
    print("李小龙")

# async def fun():  # 主协程函数
#     print("开始")
#     # task1 = asyncio.create_task(func1())
#     # task2 = asyncio.create_task(func2())
    
#     print("结束")
#     # first = await task1 # 等待结束
#     # second = await task2 # 等待结束

# asyncio.run(fun())

# 常用写法
# async def fun():  # 主协程函数
#     print("开始")
#     myList = [asyncio.create_task(func1(), name="t1"),
#               asyncio.create_task(func2(),name="t2")]

#     print("结束")
#     myFinal, myWait = await asyncio.wait(myList)
#     print(f"完成的:{myFinal}")
#     print(f"等待的:{myWait}")

# asyncio.run(fun())

# 简写
myList = [func1(),func2()]
myFinal, myWait = asyncio.run(asyncio.wait(myList)) 
print(myFinal)
print(myWait)




