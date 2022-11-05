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

## 引用

### 给变量取别名

```C++
#include <iostream>
using namespace std;

int main()
{
    // 引用基本语法 &别名 = 原名
    int a = 10;  //引用必须初始化，一旦初始化就不能更改
    // 创建引用
    int &b = a;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    // 一旦初始化就不能更改
    int c = 20;
    b = c; // 赋值操作而不是更改引用
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "c=" << c << endl;


    b = 100;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    return 0;
}
```

### 引用做函数参数

```C++
#include <iostream>
using namespace std;

// 1.值传递
void mySwap01(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

// 2.地址传递
void mySwap02(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 3.引用传递
void mySwap03(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10;
    int b = 20;
    // mySwap01(a, b); //值传递
    // mySwap02(&a, &b); // 地址传递 形参修饰实参
    mySwap03(a, b);  // 引用传递 形参修饰实参
    cout << "01a=" << a << endl;
    cout << "01b=" << b << endl;
    return 0;
}
```

引用的本质在 C++内部实现是一个引用常量 int \* const ref = &a

### 常量引用

```C++
#include <iostream>
using namespace std;
void showValue(const int &val)
{
    // val = 1000; // 加入const 不能修改数据
    cout << "val = " << val << endl;
}
int main()
{
    //常量引用
    // 用来修饰形参 防止误操作
    // 加上const之后 编译器将代码修改 int temp = 10; const int &ref = temp;
    // int a = 10;
    // int &ref = 10; //不合法
    // const int &ref = 10; //引用必须引一块合法的内存空间
    // ref  = 10; //加入const后只读 不可修改
    int a =100;
    showValue(a);
    cout << "a=" << a << endl; //  引用a的值被改变
}
```

## 函数提高

### 函数默认参数

```C++
#include <iostream>
using namespace std;

int func(int a, int b = 20, int c = 30) // 如果自己传入数据，就用自己的数据，如果没有，就用默认值
{
    return a + b + c;
}

int func2(int a, int b = 10, int c = 10, int d = 20); //声明有默认参数 函数实现不能有默认参数


int main()
{
    cout << func(10, 30) << endl;
    cout << func2(2) << endl;
    // system("pause");
    return 0;
}
int func2(int a, int b, int c, int d) //前面有参数赋值后面必须赋值
{
    return a + b + c + d;
}
```

### 函数占位参数

语法： `返回值类型 函数名 (数据类型) {}`

```C++
#include <iostream>
using namespace std;

// 占位参数
void func(int a, int) //现在占位参数还用不到
// void func(int a, int = 10) //默认参数
{
    cout << "this is function " << endl;
}

int main()
{
    func(10, 10);
    return 0;
}
```

### 函数重载

作用：函数名相同，提高复用性

满足条件：

1.同一个作用域

2.函数名称相同

3.函数名类型不同 或者 个数不同 或者 顺序不同

```C++
#include <iostream>
using namespace std;
void func() 
{
    cout << "func的调用 " << endl;
}

void func(int a) //个数不同
{
    cout << "func的调用2 " << endl;
}

void func(double a, int b) //类型不同
{
    cout << "func的调用3 " << endl;
}
void func(int b, double a) //顺序不同
{
    cout << "func的调用4 " << endl;
}

int main()
{
    func();
    return 0;
}
```

引用作为函数重载的条件

