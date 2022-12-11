# C++核心编程

## 1 内存分区模型

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

## 2 引用

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

## 3 函数提高

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

## 4 类和对象

### 4.1 封装

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

### 4.2 对象初始化与清理

#### 4.2.1 构造函数和析构函数

构造函数：主要为了创建对象是为对象的成员属性赋值，构造函数由编译器自动调用，无需手动调用

析构函数： 主要作用对象销毁前系统的自动调用，执行一些清理工作。

构造函数语法： 类名(){}

析构函数语法：~类名(){}

```C++
#include<iostream>
using namespace std;

// 对象的初始化和清理
// 1.构造函数 进行初始化操作

class Person
{
public:
    // 1.构造函数
    // 没有返回值 不用写void
    // 函数与类名相同
    // 构造函数可以有参数 可以发生重载
    // 创建对象的时候 函数自动调用，而且只调用一次
    Person()
    {
        cout << "Person构造函数的引用" << endl;
    }
    // 2.析构函数 进行清理的操作
    // 没有返回值 不用void
    // 函数名和类型名相同 在名称前加~
    // 函数名不可以有参数 不可以重载
    // 对象销毁前 会自动调用 而且智慧调用一次
    ~Person()
    {
        cout << "Person 的析构函数调用" << endl;
    }
};
// 构造和析构函数都是必须有的实现，如果我们不提供，编译器会提供一个空实现的构造析构函数
void test01()
{
    Person P; //在在栈上的数据，test01执行完毕释放这个对象
}

int main()
{
    // test01();
    Person p;
    system("pause");
}
```

#### 4.2.2 构造函数的分类和调用

两种分类方式：

按参数分类：有参构造和无参构造

按类型分类： 普通构造和拷贝构造

三种调用方式：

括号法 显示法 隐式转换法

```C++
#include <iostream>
using namespace std;

// 1.构造函数分类及调用
// 分类
class Person
{
public:
    // 普通构造函数
    Person()
    {
        cout << "这是无参构造函数调用" << endl;
    }
    Person(int a)
    {
        age = a;
        cout << "这是有参构造函数调用" << endl;
    }
    // 拷贝构造函数
    Person(const Person &p)
    {
        // 将传入的人身上的所有属性,拷贝到我身上
        age = p.age;
        cout << "这是拷贝构造函数调用" << endl;
    }

    // 析构函数
    ~Person()
    {
        cout << "这是析构函数" << endl;
    }
    int age;
};
// 调用
void test01()
{
    // // 1.括号法
    // // 注意事项1 调用默认构造函数时,不要加(),会被编译器认为是函数的声明Person p1();
    // Person p1;     //默认函数构造
    // Person p2(10); // 有参构造函数
    // Person p3(p2); // 拷贝构造函数
    // 2.显示法
    Person p1;
    Person p2 = Person(10); // 有参构造
    Person p3 = Person(p3); // 拷贝构造
    // Person(10); //匿名对象 特点:当前行执行结束后,系统会自动回收匿名对象
    // cout << "aaa" << endl;
    // 注意事项2 不要利用拷贝构造函数初始化匿名对象 编译器会认为 Person(p3) === Person(p3) 对象声明
    // 3.隐式转换法
    Person p4 = 10; // 相当于写了 Person p4 = Person(10);
    Person p5 = p4; // 拷贝构造
}

int main()
{
    test01();
    system("pause");
}
```

#### 4.2.3 拷贝构造函数调用时机

C++拷贝构造函数一般三种情况

```C++
#include <iostream>
using namespace std;

class Person
{
public:
    int m_Age;
    Person()
    {
        cout << "默认构造函数" << endl;
    }
    Person(int age)
    {
        m_Age = age;
        cout << "有参构造函数" << endl;
    }
    Person(const Person &p)
    {
        m_Age = p.m_Age;
        cout << "拷贝构造函数" << endl;
    }
    ~Person()
    {
        cout << "析构函数" << endl;
    }
};
// 构造函数的调用时机
// 1.使用一个已经创建完毕的对象来初始化对象
void test01()
{
    Person p1(20);
    Person p2(p1);
    cout << "p2的年龄:" << p2.m_Age << endl;
}
// 2.值传递的方式给函数参数传值
void doWork(Person p)
{
}
void test02()
{
    Person p;
    doWork(p);

}
// 3.值方式返回函数对象
Person doWork2()
{
    Person p1;
    return p1;
}
void test03()
{
    Person p = doWork2();
}
int main()
{
    // test01();
    // test02();
    test03();
    system("pause");
    return 0;
}
```

#### 4.2.4 构造函数调用规则

默认情况下，C++编译器至少给一类添加 3 个函数

1.默认构造函数(无参，函数体为空)

2.默认析构函数(无参 函数体为空)

3.默认拷贝构造函数,对属性进行值拷贝

```C++
#include <iostream>
using namespace std;
class Person
{
    // 构造函数的调用规则
    // 1.创建一个类,c++会添加三个函数
    // 默认函数
    // 析构函数
    // 拷贝构造

    // 2.如果我们写了有参构造函数,编译器不在提供默认构造,依然提供拷贝构造
    // test02
public:
    // Person()
    // {
    //     cout << "默认构造函数" << endl;
    // }
    Person(int age)
    {
        cout << "有参构造函数" << endl;
        m_Age = age;
    }
    ~Person()
    {
        cout << "析构函数" << endl;
    }
    Person(const Person &p)
    {
        cout << "拷贝构造函数" << endl;
        m_Age = p.m_Age;
    }
    int m_Age;
};

void test01()
{
    Person p;
    p.m_Age = 19;
    Person p2(p);
    cout << "p2年龄:" << p2.m_Age << endl;
}
void test02()
{
    Person p;
}

int main()
{
    // test01();
    test02();
    return 0;
}
```

#### 4.2.5 深拷贝与浅拷贝

浅拷贝带来的问题就是堆区的内存被重复释放

```C++
#include <iostream>
using namespace std;
class Person
{
public:
    Person()
    {
        cout << "默认构造函数" << endl;
    }
    Person(int age, int height)
    {
        cout << "有参构造函数" << endl;
        m_Age = age;
        m_Height = new int(height); //堆区数据 new int 返回int *
    }
    ~Person()
    {
        // 析构代码，将堆区开辟数据做释放操作
        if (m_Height != NULL)
        {
            delete m_Height;
            m_Height = NULL;
        }
        cout << "析构函数" << endl;
    }
    // 自己实现拷贝构造函数 解决浅拷贝带来的问题
    Person(const Person &p)
    {
        cout << "拷贝构造函数" << endl;
        m_Age = p.m_Age;
        // m_Height = p.m_Height; // 编译器默认实现这些代码 等号赋值操作浅拷贝
        //深拷贝操作
        m_Height = new int (*p.m_Height);
    }
    int m_Age;     //年龄
    int *m_Height; //身高
};

void test01()
{
    Person p1(18, 160);
    cout << "p1年龄:" << p1.m_Age << endl
         << "p1身高:" << *p1.m_Height << endl;
    Person p2(p1);
    cout << "p2年龄:" << p2.m_Age << endl
         << "p2身高:" << *p2.m_Height << endl;
}
int main()
{
    test01();
    return 0;
}
```

#### 4.2.6 初始化列表

作用：用来初始化属性

语法：构造函数():属性 1(值 1),属性 2(值 2).....{}

```C++

#include <iostream>
using namespace std;
class Person
{
public:
//    // 传统初始化操作
//     Person(int a, int b, int c)
//     {
//         m_A =a;
//         m_B = b;
//         m_C = c;

//         cout << "有参构造函数" << endl;
//     }
    int m_A;
    int m_B;
    int m_C;
    // 初始化列表初始化属性
    // Person():m_A(10), m_B(20), m_C(20)
    Person(int a, int b, int c):m_A(a), m_B(b), m_C(c)
    {

    }
};

void test01()
{
    // Person p1(10, 20, 20); // 传统初始化
    // Person p1; // 初始化列表
    Person p1(10,20,20);
    cout << "mA:" << p1.m_A << endl
         << "mB:" << p1.m_B << endl
         << "mC:" << p1.m_C << endl;
}
int main()
{
    test01();
    return 0;
}
```

#### 4.2.7 类对象作为类成员

C++ 类中的成员可以是另一个类的的对象,我们称该成员为对象成员.

```C++
#include <iostream>
using namespace std;
#include <string.h>
//类对象作为类成员

// 手机类
class Phone
{
public:
    //手机名称
    Phone(string pName)
    {
        m_Pname = pName;
        cout << "Phone的构造函数调用" << endl;
    }
    string m_Pname;
};
// 人类
class Person
{
public:
    Person(string name, string pName) : m_Name(name), m_Phone(pName)
    {
        cout << "Person 的构造函数调用" << endl;
    }
    // 姓名
    string m_Name;
    // 手机
    Phone m_Phone;
};
// 当其他类对象作为本类成员,构造时候先构造类对象, 在构造自身
// 析构函数顺序与构造顺序相反
void test01()
{
    Person p("张三", "ipone 100 MAX");
    cout << p.m_Name << "拿着" << p.m_Phone.m_Pname << endl;
}
int main()
{
    test01();
    // system("pause");
    return 0;
}
```

#### 4.2.8 静态成员

静态成员变量

- 所有对象共享同一份数据
- 在编译阶段分配内存
- 类内声明,类外初始化

静态成员函数

- 所有对象共享同一个函数
- 静态成员函数只能访问静态成员变量

```C++
#include <iostream>
using namespace std;

// 静态成员变量
class Person
{
public:
    //所有对象都共享同一份数据
    // 编译阶段分配内存
    // 类内声明,类外初始化操作
    static int m_A;
// 静态成员变量也是有访问权限的
private:
    static int m_B;
};
// int Person :: m_B = 200; // private 不可访问
int Person :: m_A = 100; //类外初始化

void test01()
{
    Person p;
    cout << p.m_A << endl;
    Person p2;
    p2.m_A = 200;
    cout << p.m_A << endl;
}
void test02()
{
    // 静态成员变量 不属于某个对象上 所有对象都共享同一份数据
    // 因此静态变量有两种访问方式
    // 1.通过对象名进行访问
    Person p;
    cout << p.m_A << endl;

    // 2. 通过类名进行访问
    cout << Person::m_A << endl;
}
int main()
{
    // test01();
    test02();
    return 0;
}
```

```C++
#include <iostream>
using namespace std;

// 静态成员函数
//所有对象都共享同一函数
// 静态成员函数只能访问静态成员变量
class Person
{
public:
    static void func()
    {
        m_A = 100; // 静态成员函数访问静态成员变量
        // m_B = 200; // 不可访问非静态成员变量
        cout << "static void functiop 调用" << endl;
    }
    static int m_A; //静态成员变量
    int m_B;        //非静态成员变量
    // 静态成员函数也是有访问权限的
private:
    static void func()
    {
        m_A = 100; // 静态成员函数访问静态成员变量
        // m_B = 200; // 不可访问非静态成员变量
        cout << "static void functiop 调用" << endl;
    }
};
int Person ::m_A = 0;
//有两种访问方式
void test01()
{
    // 1.通过对象进行访问
    Person p;
    p.func();
    // 2，通过类名进行访问
    Person ::func();
}
int main()
{
    test01();
    return 0;
}
```

### 4.3 C++ 对象模型和 this 指针

#### 4.3.1 成员变量与成员函数分开存储

只有非静态成员变量,属于类对象上,占用类的内存

```C++
#include<iostream>
using namespace std;
// 成员变量和成员函数分开储存
class Person
{
    int m_A; // 非静态成员变量,属于类对象上
    static int m_B; //静态成员变量  不属于类对象上
    void fun(){} //  非静态成员函数 不属于类对象上
    static void func2(){} //静态成员函数 不属于类对象上

};
int Person :: m_B = 0; //初始化
void test01()
{
    Person p;
    // 空对象占用内存空间:1
    // C++编译器给每个空对象也分配一个字节空间,区分空对象占内存的位置
    // 空对象也应该有一个独一唯二的地址
    cout << "size of p =" << sizeof(p) << endl;
}
void test02()
{
    Person p;
    cout << "size of p =" << sizeof(p) << endl;
}
int main()
{
    // test01();
    test02();
    return 0;
}
```

#### 4.3.2 this 指针概念

- this 指针指向被调用成员函数所属的对象
- 不需要定义 直接使用

用途

- 当形参与成员变量重名时,可用 this 指针来区分
- 在类的非静态成员函数返回对象本身,可以用 return \*this

```C++
#include <iostream>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        // age = age; //名字冲突
        this->age = age; // this 指针指向被调用成员函数所属的对象,谁调用指向谁
    }
    Person &PersonAddAge(Person &p)
    {
        this->age += p.age;
        return *this; //  /*this 指向对象本体
    }
    int age;
};
// 1.解决名称冲突
void test01()
{
    Person p1(18);
    cout << "p1的年龄为:" << p1.age << endl;
}
// 2.返回队形本身用*this
void test02()
{
    Person p1(10);
    Person p2(13);
    p2.PersonAddAge(p1).PersonAddAge(p1); // 链式编程
    cout << "p2的年龄为:" << p2.age << endl;
}
int main()
{
    test01();
    test02();
    return 0;
}
```

#### 4.3.3 空指针访问成员函数

```C++
#include <iostream>
using namespace std;
// 空指针调用成员函数
class Person
{
public:
    void showClassName()
    {
        cout << "this is Person Class" << endl;
    }
    void showPersonAge()
    {
        // 报错原因是因为传入的指针为NULL
        if (this == NULL)
        {
            return;
        }
        cout << "age = " << m_Age << endl;
    }
    int m_Age;
};
void test01()
{
    Person *p = NULL;
    p->showClassName();
    p->showPersonAge();
}
int main()
{
    test01();
    return 0;
}
```

#### const 修饰成员函数

常函数

- 成员函数后加 const 我们称之为常函数
- 常函数内不可以修改成员属性
- 成员属性声明中加上关键字 mutable 后,在常函数后依然可以修改

常对象

- 声明对象加上 const 称该对象为常对象
- 常对象只能调用常函数

```C++
#include <iostream>
using namespace std;
// 常函数
class Person
{
public:
    // this指针的本质 是指针常量 指针的指向是不可修改的
    // 在成员函数后面加const ,修饰的是this指针指向 让指针指向的值不可以修改
    void showPerson() const
    {
        // this->m_A = 100; //不可以修改
        // this = NULL; //this 指针不可以修改指针指向
        this->m_B = 100;
        cout << m_B << endl;
        cout << m_A << endl;
    }
    void func(){}

    int m_A;
    mutable int m_B; //加上关键字可以修改
};
void test01()
{
    Person p;
    p.showPerson();
}
// 常对象
void test02()
{
    const Person p; // 在对象前加const ,变为常对象
    // p.m_A = 100;
    p.m_B = 200;
    cout << p.m_B << endl;
    // 常对象只能调用常函数
    p.showPerson();
    p.func();// 不可调用
}
int main()
{
    // test01();
    test02();
    return 0;
}
```

### 4.4 友元

目的让一个函数和类 访问另一个类中私有变量

全局函数做友元

类做友元

成员函数做友元

#### 4.4.1 全局函数做友元

```C++
#include <iostream>
using namespace std;
#include <string.h>
class Building
{
    // 友元可以访问私有
    friend void goodGay(Building *building);
    // 建筑物的类
public:
    Building()
    {
        m_SettingRoom = "客厅";
        m_BedRoom = "卧室";
    }

public:
    string m_SettingRoom; // 客厅
private:
    string m_BedRoom; // 卧室
};
// 全局函数
void goodGay(Building *building)
{
    cout << "好基友全局函数 正在访问:" << building->m_SettingRoom << endl;
    cout << "好基友全局函数 正在访问:" << building->m_BedRoom << endl; // 私有属性不可访问
}
void test01()
{
    Building building;
    goodGay(&building);
}
int main()
{
    test01();
    return 0;
}
```

#### 4.4.2 类做友元

```C++
#include <iostream>
using namespace std;
#include <string.h>
class Building
{
    // 类做友元
    friend class GoodGay;
public:
    Building();
public:
    string m_SettingRoom; //客厅
private:
    string m_BedRoom; // 卧室
};
// 类做友元
class GoodGay
{
public:
    GoodGay();
public:
    void visit(); //参观函数 访问building的属性
    Building *building;
};
// 类外写成员函数
Building::Building()
{
    m_SettingRoom = "客厅";
    m_BedRoom = "卧室";
}
GoodGay::GoodGay()
{
    //创建建筑物的对象
    building = new Building;
}
void GoodGay::visit()
{
    cout << "好基友类正在访问：" << building ->m_SettingRoom << endl;
    cout << "好基友类正在访问：" << building ->m_BedRoom << endl;
}
void test01()
{
    GoodGay hh;
    hh.visit();
}
int main()
{
    test01();
    return 0;
}
```

#### 4.4.3 成员函数做友元

此代码运行有问题 不想看 20221129

```C++
#include <iostream>
using namespace std;
#include <string.h>
class GoodGay
{
public:
    GoodGay();
    void visit1(); //访问building的私有属性
    void visit2(); //不可访问building的私有属性
private:
    Building *building;
};
class Building
{
    // 友元
    friend void GoodGay::visit1();
public:
    Building();
public:
    string m_SettingRoom; //客厅
private:
    string m_BedRoom; // 卧室
};

// 类外写成员函数
Building::Building()
{
    m_SettingRoom = "客厅";
    m_BedRoom = "卧室";
}
GoodGay::GoodGay()
{
    //创建建筑物的对象
    building = new Building;
}
void GoodGay::visit1()
{
    cout << "visit1正在访问：" << building ->m_SettingRoom << endl;
    cout << "visit1正在访问：" << building ->m_BedRoom << endl;
}
void GoodGay::visit2()
{
    cout << "visit2正在访问：" << building ->m_SettingRoom << endl;
    // cout << "visit2正在访问：" << building ->m_BedRoom << endl;
}
void test01()
{
    GoodGay hh;
    hh.visit1();
    hh.visit2();
}
int main()
{
    test01();
    return 0;
}
```

### 4.5 运算符重载

运算符重载概念：对已有的运算符重新进行定义，赋予另一种功能，以适应不同的功能

对于内置的数据类型编译器知道如何运算 int a = 10; int b = 10; int c = a + b;

#### 4.5.1 加法运算符重载

```C++
# include<iostream>
using namespace std;
// 加号运算符重载
class Person
{
public:
    // // 1.成员函数重载+号
    // Person operator+(Person &p)
    // {
    //     Person temp;
    //     temp.m_A = this ->m_A + p.m_A;
    //     temp.m_B = this ->m_B + p.m_B;
    //     return  temp;
    // }
    // 成员函数本质调用 Person p3 = p1.operator+(p2);
    int m_A;
    int m_B;

};
// 全局函数重载
// 本质调用 Person p3 = operator+(p1, p2)
Person operator+ (Person &p1, Person &p2)
{
        Person temp;
        temp.m_A = p1.m_A + p2.m_A;
        temp.m_B = p1.m_B + p2.m_B;
        return  temp;
}
// 函数重载
Person operator+ (Person &p1, int num)
{
        Person temp;
        temp.m_A = p1.m_A + num;
        temp.m_B = p1.m_B + num;
        return  temp;
}
void test01()
{
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;
    Person p2;
    p2.m_A = 10;
    p2.m_B = 10;

    Person p3 = p1 + p2;
    Person p4 = p1 + 100; // Person + int
    cout << "p3.m_A=" << p3.m_A << endl;
    cout << "p3.m_B=" << p3.m_B << endl;
    cout << "p4.m_A=" << p4.m_A << endl;
    cout << "p4.m_B=" << p4.m_B << endl;
}

int main()
{
    test01();
    return 0;
}
```

#### 4.5.2 左移运算符重载

```C++
#include<iostream>
using namespace std;

class Person
{
public:
    Person(int a, int b)
    {
        m_A = a;
        m_B = b;
    }
    friend ostream & operator<<(ostream & cout, Person &p);
private:

    // 利用成员函数重载左移运算符
    // 无法利用成员函数重载<<运算符 因为无法实现 cout在左侧
    // void operator<< (cout)
    int m_A;
    int m_B;
};
// 只能利用全局函数来左移重载运算符
ostream & operator<<(ostream & cout, Person &p) // 本质 operator<<(cout, p) 简化 cout << p
{
    cout << "m_A=" << p.m_A << "m_B=" << p.m_B;
    return cout;
}
void test01()
{
    Person p(10, 10);
    cout << p << endl;
}
int main()
{
    test01();
    return 0;
}
```

总结：重载左移运算符配合友元可以实现输出自定义数据类型

#### 4.5.3 递增运算符重载

作用：通过重载递增运算符 实现自己的整型数据

```C++
#include <iostream>
using namespace std;
// 重载递增运算符
//自定义整型

class MyInterger
{=
    friend ostream &operator<<(ostream &cout, MyInterger myint);

public:
    MyInterger()
    {
        m_Num = 0;
    }
    // 重载前置++运算符
    MyInterger operator++()
    {
        ++m_Num;
        return *this;
    }
    // 重载后置++运算符
    MyInterger operator++(int)  //int 占位参数 区分前置/后置递增
    {
        MyInterger temp = *this;
        m_Num++;
        return temp;
    }

private:
    int m_Num;
};

ostream &operator<<(ostream &cout, MyInterger myint)
{
    cout << myint.m_Num;
    return cout;
}
void test01()
{
    MyInterger myint;
    cout << ++(++myint) << endl;
}
void test02()
{
    MyInterger myint;
    cout << myint++ << endl;
    cout << myint << endl;
}
int main()
{
    test01();
    test02();
    return 0;
}
```

#### 4.5.4 赋值运算符重载

```C++
#include <iostream>
using namespace std;
// 赋值运算符重载

class Person
{
public:
    Person(int age)
    {
        m_Age = new int(age);
    }
// private:
    int *m_Age;
    ~Person()  // 堆区重复释放
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }
    // 重载赋值运算符
    Person &operator=(Person &p)
    {
        //编译器是提供浅拷贝
        // m_Age = p.m_Age;
        // 应该先判断堆区是否有属性，如果有先释放干净，然后再深拷贝
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
        //深拷贝
        m_Age = new int(*p.m_Age);
        return *this;

    }
};
void test01()
{
    Person p1(18);
    Person p2(20);
    Person p3(30);

    p3 = p2 = p1;
    cout << "p1的年龄为" << *p1.m_Age << endl;
    cout << "p2的年龄为" << *p2.m_Age << endl;
}
int main()
{
    test01();
    return 0;
}
```

#### 4.5.5 关系运算符重载

```C++
#include <iostream>
using namespace std;
// 关系运算符重载

class Person
{
public:
    Person(string name, int age)
    {
        m_Name = name;
        m_Age = age;
    }

    string m_Name;
    int m_Age;
    // 重载关系运算符
    bool operator==(Person &p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        return false;
    }
};
void test01()
{
    Person p1("Tom", 18);
    Person p2("Tom", 8);
    if (p1 == p2)
    {
        cout << "p1=p2" << endl;
    }
    else
    {
        cout << "p1!=p2" << endl;
    }
}
int main()
{
    test01();
    return 0;
}
```

#### 4.5.6 函数调用运算符重载

- 函数调用运算符（）可以重载
- 由于重载后使用的方法非常像函数的调用，因此被称为仿函数
- 仿函数没有固定语法，非常灵活

```C++
#include <iostream>
using namespace std;
// 函数运算符重载
// 打印输出类
class MyPrint
{
public:
    // 重载函数运算符
    void operator()(string test)
    {
        cout << test << endl;
    }
};
void test01()
{
    MyPrint myPrint;
    myPrint("hello world");//仿函数
}
// 加法类
class MyAdd
{
public:

    int operator()(int num1, int num2)
    {
        return num1 + num2;
    }
};
void test02()
{
    MyAdd myadd;
    int ret = myadd(100, 100);
    cout << ret << endl;
    // 匿名函数对象
    cout << MyAdd()(100,100) << endl;
}

int main()
{
    test01();
    test02();
    return 0;
}
```

### 4.6 继承

#### 4.6.1 继承的基本用法

```C++
#include <iostream>
using namespace std;

// class Java
// {
// public:
//     void header()
//     {
//         cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//     }
//     void footer()
//     {
//         cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//     }
//     void left()
//     {
//         cout << "Java、Python、C++...(公共分类列表)" << endl;
//     }
//     void content()
//     {
//         cout << "Java学科视频" << endl;
//     }

// };
// class Python
// {
// public:
//     void header()
//     {
//         cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//     }
//     void footer()
//     {
//         cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//     }
//     void left()
//     {
//         cout << "Java、Python、C++...(公共分类列表)" << endl;
//     }
//     void content()
//     {
//         cout << "Python学科视频" << endl;
//     }
// };
// class Cpp
// {
// public:
//     void header()
//     {
//         cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//     }
//     void footer()
//     {
//         cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//     }
//     void left()
//     {
//         cout << "Java、Python、C++...(公共分类列表)" << endl;
//     }
//     void content()
//     {
//         cout << "C++学科视频" << endl;
//     }
// };
// 继承好处 减少代码重复
// 语法：class 子类 ：继承方式 父类
// 子类 也称派生类
// 父类 也称为基类
// 继承实现页面
class BasePage
{
public:
    void header()
    {
        cout << "首页、公开课、登录、注册...(公共头部)" << endl;
    }
    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
    }
    void left()
    {
        cout << "Java、Python、C++...(公共分类列表)" << endl;
    }
};
class Java : public BasePage
{
public:
    void content()
    {
        cout << "Java学科视频" << endl;
    }
};
class Python : public BasePage
{
public:
    void content()
    {
        cout << "Python学科视频" << endl;
    }
};
void test01()
{
    cout << "Java下载视频页面如下" << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "-----------------------------" << endl;
    cout << "Python下载视频页面如下" << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "-----------------------------" << endl;
    cout << "C++下载视频页面如下" << endl;
}
int main()
{
    test01();
    return 0;
}
```

#### 4.6.2 继承方式

继承方式三种：

- 公共继承
- 保护继承
- 私有继承

```C++
#include <iostream>
using namespace std;

class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son1 : public Base1
{
    void func()
    {
        m_A = 10; // 父类公共权限内容到子类依然是公共权限
        m_B = 10; // 父类保护权限到子类依然是保护权限
        // m_C = 10; // 私有权限不可访问
    }
};
class Base2
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};
class Son2 : protected Base2
{
    void func()
    {
        m_A = 10; // 父类公共权限内容到子类变为保护权限
        m_B = 10; // 父类保护权限到子类依然是保护权限
        // m_C = 10; // 私有权限不可访问
    }
};
class Base3
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};
class Son3 : private Base3
{
public:
    void func()
    {
        m_A = 100; //父类公共成员到子类变为私有权限
        m_B = 100; //父类保护成员到子类变为私有权限
        // m_C = 100; // 私有变量访问不到
    }

};
void test01()
{
    Son1 s1;
    s1.m_A = 100;
    // s1.m_B = 100; // 类外访问不到保护权限

}
void test02()
{
    Son2 s1;
    // s1.m_A = 100; // 类外访问不到保护权限
    // s1.m_B = 100; // 类外访问不到保护权限
}
void test03()
{
    Son3 s1;
    // s1.m_A = 100; // 类外访问不到私有权限
    // s1.m_B = 100; // 类外访问不到私有权限
}

int main()
{
    test01();
    return 0;
}
```

#### 4.6.3 继承中的对象模型

```C++
#include <iostream>
using namespace std;

class Base
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C; 
};

class Son : public Base
{
    // 父类中所有非静态成员属性都会被继承
public:
    int m_D;
};

void test01()
{
    cout << "size of Son =" << sizeof(Son) << endl;
}

int main()
{
    test01();
    return 0;
}
```
