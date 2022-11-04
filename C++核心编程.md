# C++核心编程

## 内存分区模型

### 内存运行前

代码区：存放二进制代码

全局区：全局变量 静态变量 常量(字符串常量 const 修饰的全局变量)

### 内存运行后

栈区

注意事项：编译器管理开辟和释放 不要返回局部变量的地址

堆区

程序员分配释放 若程序员不释放，程序结束后由操作系统回收

在 C++中主要利用 new 在堆区开辟内存


```C++
#include <iostream>
using namespace std;

int *func()
{
    //利用new关键字 可以将数据开辟到堆区
    // new 返回是 该数据类型的指针
    int *p = new int(10);
    return p;  
}

void test()
{
    // 创建10整型数据的数组
    int *arr = new int[10]; //数组有十个元素
    delete [] arr; //释放数组要加[]
}
int main()
{
    //在堆区开辟数据
    int *p = func();
    cout << *p << endl;
    //释放内存
    // delete p;


    system("pause");
    return 0;
}
```
