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

## 类和对象

### 封装

```C++
#include <iostream>
using namespace std;
#include <string>
// class设计一个类
class Student
{
    // 访问权限
    // 公共权限
public:
    // 类中的属性和行为 我们统一称为成员
    //属性  成员属性 成员变量
    // 行为 成员函数 成员方法

    // 属性
    // 姓名 学号
    string m_Name;
    int m_id;
    // 行为
    // 显示姓名与学号
    void showStudent()
    {
        cout << "姓名：" << m_Name << "学号：" << m_id << endl;
    }
    // 给姓名赋值
    void setName(string name)
    {
        m_Name = name;
    }
};

int main()
{
    // 实例化
    Student s1;
    s1.setName("张三");
    s1.m_id = 12357;
    s1.showStudent();
}
```

#### 访问权限

//三种

// 公共权限 public 成员类内可以访问 类外可以访问

// 保护权限 成员类内可以访问 类外不可以访问

// 私有权限 成员类内可以访问 类外不可以访问

```C++
#include <iostream>
using namespace std;
#include <string>
// class设计一个类
class Person
{
    // 访问权限
    // 公共权限
public:
    // 公共权限
    string m_Name;

protected:
    // 保护权限
    string m_Car;

private:
    // 私有权限
    int m_Password;

public:
    void fun()
    {
        m_Name = "张三";
        m_Car = "拖拉机";
        m_Password = 123456; // 类内可以访问
    }
};
int main()
    {
        // 实例化
        Person p1;
        p1.m_Name = "张三";
        // p1.m_Car = "拖拉机"; //保护权限内容 类外访问不到
        // p1.m_Password = 123456; //私有权限内容 类外访问不到
    }
```

#### struct 和 class 区别

struct 默认权限是公共权限 public

class 默认权限是私有 private

```C++
#include <iostream>
using namespace std;
#include <string>
// class设计一个类
class C1
{
    int m_A; // 默认权限 是私有
};

struct C2
{
    int m_A; // 默认权限是公共
};
int main()
    {
        // 实例化
        C1 c1;
        c1.m_A = 100; //私有不可访问
        C2 c2;
        c2.m_A = 100; // struct 可以访问
    }

```

#### 成员属性设置为私有

自己控制读写的权限

对于写可以检测数据的有效性

```C++
#include <iostream>
using namespace std;
#include <string>
// class设计一个类
class Person
{
public:
    // 设置姓名
    void setName(string name)
    {
        m_Name = name;
    }
    // 获取姓名
    string getName()
    {
         return m_Name;
    }
    // 获取年龄
    int getAgg()
    {
        m_age = 0; //只读 初始化年龄
        return m_age;
    }
    // 设置情人 只写
    void setLover(string lover)
    {
        m_lover = lover;
    }
    // 设置年龄检测
    void set_Age(int age)
    {
        if(age < 0 || age > 150)
        {
            cout << "输入年龄不对，请检查输入" << endl;
            return;
        }
        m_age = age;
    }
private:
    // 姓名
    string m_Name; //可读可写
    // 年龄
    int m_age; // 只读
    // 情人
    string m_lover; // 只写
};

int main()
    {
        // 实例化
        Person p;
        p.setName("张三");
        cout << "姓名为：" <<  p.getName() << endl;
        cout << "年龄为:" << p.getAgg() << endl;
        // p.m_age = 18; // 只读不可修改
        p.setLover("Lucy");
        // cout << "情人为" << p.setLover <<endl; // 只写 不可以访问
        p.set_Age(1000);
        return 0;
    }
```

#### 练习案例 1

```C++
// 设置立方体类
// 求出立方体的面积和体积
// 分别用全局函数和成员函数判断两个立方体是否相等
#include <iostream>
using namespace std;
#include <string>
// 设置立方体类
class Cube
{
    // 设置公共属性 从私有中拿出
public:
    // 设置长宽高
    void setLong(int chang)
    {
        m_Long = chang;
    }
    void setWidth(int width)
    {
        m_Width = width;
    }
    void setHigth(int higth)
    {
        m_Higth = higth;
    }
    // 获取长宽高
    int getLong()
    {
        return m_Long;
    }
    int getWidth()
    {
        return m_Width;
    }
    int getHigth()
    {
        return m_Higth;
    }
    //行为 获取面积与体积
    int calS()
    {
        return 2 * m_Long * m_Width + 2 * m_Long * m_Higth + 2 * m_Width * m_Higth;
    }
    int calV()
    {
        return m_Higth * m_Long * m_Width;
    }
     // 利用成员函数判断相等
    bool isSameByClass(Cube &c)
    {
        if (m_Long == c.getLong() && m_Width == c.getWidth() && m_Higth == c.getHigth())
    {
        return true;
    }
    return false;
    }
private:
    //属性
    // 长宽高
    int m_Long;
    int m_Width;
    int m_Higth;
};
// 利用全局函数判断相等
bool isSame(Cube &c1, Cube &c2)
{
    if (c1.getLong() == c2.getLong() && c1.getWidth() == c2.getWidth() && c1.getHigth() == c2.getHigth())
    {
        return true;
    }
    return false;
}
int main()
{
    // 实例化
    Cube c1;
    c1.setLong(10);
    c1.setWidth(10);
    c1.setHigth(10);
    cout << "面积：" << c1.calS() << endl
         << "体积：" << c1.calV() << endl;

    Cube c2;
    c2.setLong(10);
    c2.setWidth(90);
    c2.setHigth(10);
    cout << "面积：" << c2.calS() << endl
         << "体积：" << c2.calV() << endl;
    // 利用全局函数判断相等
    bool ret = isSame(c1, c2);
    if(ret)
    {
        cout << "c1和c2相等。" << endl;
    }
    else
    {
        cout << "c1和c2不相等。" << endl;
    }

    //  利用成员函数判断相等
    bool ret2 = c1.isSameByClass(c2);
    if(ret2)
    {
        cout << "成员函数判断" << endl;
        cout << "c1和c2相等。" << endl;
    }
    else
    {   cout << "成员函数判断" << endl;
        cout << "c1和c2不相等。" << endl;
    }

    return 0;
}
```
