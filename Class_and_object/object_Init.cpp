// #include <iostream>
// using namespace std;
// class Person
// {
// public:
//     Person()
//     {
//         cout << "默认构造函数" << endl;
//     }
//     Person(int age, int height)
//     {
//         cout << "有参构造函数" << endl;
//         m_Age = age;
//         m_Height = new int(height); //堆区数据 new int 返回int *
//     }
//     ~Person()
//     {
//         // 析构代码，将堆区开辟数据做释放操作
//         if (m_Height != NULL)
//         {
//             delete m_Height;
//             m_Height = NULL;
//         }
//         cout << "析构函数" << endl;
//     }
//     // 自己实现拷贝构造函数 解决浅拷贝带来的问题
//     Person(const Person &p)
//     {
//         cout << "拷贝构造函数" << endl;
//         m_Age = p.m_Age;
//         // m_Height = p.m_Height; // 编译器默认实现这些代码 等号赋值操作浅拷贝
//         //深拷贝操作
//         m_Height = new int (*p.m_Height);
//     }
//     int m_Age;     //年龄
//     int *m_Height; //身高
// };

// void test01()
// {
//     Person p1(18, 160);
//     cout << "p1年龄:" << p1.m_Age << endl
//          << "p1身高:" << *p1.m_Height << endl;
//     Person p2(p1);
//     cout << "p2年龄:" << p2.m_Age << endl
//          << "p2身高:" << *p2.m_Height << endl;
// }
// int main()
// {
//     test01();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// class Person
// {
// public:
// //    // 传统初始化操作
// //     Person(int a, int b, int c)
// //     {
// //         m_A =a;
// //         m_B = b;
// //         m_C = c;

// //         cout << "有参构造函数" << endl;
// //     }
//     int m_A;
//     int m_B;
//     int m_C;
//     // 初始化列表初始化属性
//     // Person():m_A(10), m_B(20), m_C(20)
//     Person(int a, int b, int c):m_A(a), m_B(b), m_C(c)
//     {

//     }
// };

// void test01()
// {
//     // Person p1(10, 20, 20); // 传统初始化
//     // Person p1; // 初始化列表
//     Person p1(10,20,20);
//     cout << "mA:" << p1.m_A << endl
//          << "mB:" << p1.m_B << endl
//          << "mC:" << p1.m_C << endl;
// }
// int main()
// {
//     test01();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// #include <string.h>
// //类对象作为类成员

// // 手机类
// class Phone
// {
// public:
//     //手机名称
//     Phone(string pName)
//     {
//         m_Pname = pName;
//         cout << "Phone的构造函数调用" << endl;
//     }
//     string m_Pname;
// };
// // 人类
// class Person
// {
// public:
//     Person(string name, string pName) : m_Name(name), m_Phone(pName)
//     {
//         cout << "Person 的构造函数调用" << endl;
//     }
//     // 姓名
//     string m_Name;
//     // 手机
//     Phone m_Phone;
// };
// // 当其他类对象作为本类成员,构造时候先构造类对象, 在构造自身
// // 析构函数顺序与构造顺序相反
// void test01()
// {
//     Person p("张三", "ipone 100 MAX");
//     cout << p.m_Name << "拿着" << p.m_Phone.m_Pname << endl;
// }
// int main()
// {
//     test01();
//     // system("pause");
//     return 0;
// }

// #include <iostream>
// using namespace std;

// // 静态成员变量
// class Person
// {
// public:
//     //所有对象都共享同一份数据
//     // 编译阶段分配内存
//     // 类内声明,类外初始化操作
//     static int m_A;
// // 静态成员变量也是有访问权限的
// private:
//     static int m_B;
// };
// // int Person :: m_B = 200; // private 不可访问
// int Person :: m_A = 100; //类外初始化

// void test01()
// {
//     Person p;
//     cout << p.m_A << endl;
//     Person p2;
//     p2.m_A = 200;
//     cout << p.m_A << endl;
// }
// void test02()
// {
//     // 静态成员变量 不属于某个对象上 所有对象都共享同一份数据
//     // 因此静态变量有两种访问方式
//     // 1.通过对象名进行访问
//     Person p;
//     cout << p.m_A << endl;

//     // 2. 通过类名进行访问
//     cout << Person::m_A << endl;
// }
// int main()
// {
//     // test01();
//     test02();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// // 静态成员函数
// //所有对象都共享同一函数
// // 静态成员函数只能访问静态成员变量
// class Person
// {
// public:
//     static void func()
//     {
//         m_A = 100; // 静态成员函数访问静态成员变量
//         // m_B = 200; // 不可访问非静态成员变量
//         cout << "static void functiop 调用" << endl;
//     }
//     static int m_A; //静态成员变量
//     int m_B;        //非静态成员变量
//     // 静态成员函数也是有访问权限的
// private:
//     static void func()
//     {
//         m_A = 100; // 静态成员函数访问静态成员变量
//         // m_B = 200; // 不可访问非静态成员变量
//         cout << "static void functiop 调用" << endl;
//     }
// };
// int Person ::m_A = 0;
// //有两种访问方式
// void test01()
// {
//     // 1.通过对象进行访问
//     Person p;
//     p.func();
//     // 2，通过类名进行访问
//     Person ::func();
// }
// int main()
// {
//     test01();
//     return 0;
// }

// # include<iostream>
// using namespace std;
// // 加号运算符重载
// class Person
// {
// public:
//     // // 1.成员函数重载+号
//     // Person operator+(Person &p)
//     // {
//     //     Person temp;
//     //     temp.m_A = this ->m_A + p.m_A;
//     //     temp.m_B = this ->m_B + p.m_B;
//     //     return  temp;
//     // }
//     // 成员函数本质调用 Person p3 = p1.operator+(p2);
//     int m_A;
//     int m_B;

// };
// // 全局函数重载
// // 本质调用 Person p3 = operator+(p1, p2)
// Person operator+ (Person &p1, Person &p2)
// {
//         Person temp;
//         temp.m_A = p1.m_A + p2.m_A;
//         temp.m_B = p1.m_B + p2.m_B;
//         return  temp;
// }
// // 函数重载
// Person operator+ (Person &p1, int num)
// {
//         Person temp;
//         temp.m_A = p1.m_A + num;
//         temp.m_B = p1.m_B + num;
//         return  temp;
// }
// void test01()
// {
//     Person p1;
//     p1.m_A = 10;
//     p1.m_B = 10;
//     Person p2;
//     p2.m_A = 10;
//     p2.m_B = 10;

//     Person p3 = p1 + p2;
//     Person p4 = p1 + 100; // Person + int
//     cout << "p3.m_A=" << p3.m_A << endl;
//     cout << "p3.m_B=" << p3.m_B << endl;
//     cout << "p4.m_A=" << p4.m_A << endl;
//     cout << "p4.m_B=" << p4.m_B << endl;
// }

// int main()
// {
//     test01();
//     return 0;
// }

// #include<iostream>
// using namespace std;

// class Person
// {
// public:
//     Person(int a, int b)
//     {
//         m_A = a;
//         m_B = b;
//     }
//     friend ostream & operator<<(ostream & cout, Person &p);
// private:

//     // 利用成员函数重载左移运算符
//     // 无法利用成员函数重载<<运算符 因为无法实现 cout在左侧
//     // void operator<< (cout)
//     int m_A;
//     int m_B;
// };
// // 只能利用全局函数来左移重载运算符
// ostream & operator<<(ostream & cout, Person &p) // 本质 operator<<(cout, p) 简化 cout << p
// {
//     cout << "m_A=" << p.m_A << "m_B=" << p.m_B;
//     return cout;
// }
// void test01()
// {
//     Person p(10, 10);
//     cout << p << endl;
// }
// int main()
// {
//     test01();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// // 重载递增运算符
// //自定义整型

// class MyInterger
// {
//     friend ostream &operator<<(ostream &cout, MyInterger myint);

// public:
//     MyInterger()
//     {
//         m_Num = 0;
//     }
//     // 重载前置++运算符
//     MyInterger operator++()
//     {
//         ++m_Num;
//         return *this;
//     }
//     // 重载后置++运算符
//     MyInterger operator++(int)  //int 占位参数 区分前置/后置递增
//     {
//         MyInterger temp = *this;
//         m_Num++;
//         return temp;
//     }

// private:
//     int m_Num;
// };

// ostream &operator<<(ostream &cout, MyInterger myint)
// {
//     cout << myint.m_Num;
//     return cout;
// }
// void test01()
// {
//     MyInterger myint;
//     cout << ++(++myint) << endl;
// }
// void test02()
// {
//     MyInterger myint;
//     cout << myint++ << endl;
//     cout << myint << endl;
// }
// int main()
// {
//     test01();
//     test02();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// // 赋值运算符重载

// class Person
// {
// public:
//     Person(int age)
//     {
//         m_Age = new int(age);
//     }
// // private:
//     int *m_Age;
//     ~Person()  // 堆区重复释放
//     {
//         if (m_Age != NULL)
//         {
//             delete m_Age;
//             m_Age = NULL;
//         }
//     }
//     // 重载赋值运算符
//     Person &operator=(Person &p)
//     {
//         //编译器是提供浅拷贝
//         // m_Age = p.m_Age;
//         // 应该先判断堆区是否有属性，如果有先释放干净，然后再深拷贝
//         if (m_Age != NULL)
//         {
//             delete m_Age;
//             m_Age = NULL;
//         }
//         //深拷贝
//         m_Age = new int(*p.m_Age);
//         return *this;

//     }
// };
// void test01()
// {
//     Person p1(18);
//     Person p2(20);
//     Person p3(30);

//     p3 = p2 = p1;
//     cout << "p1的年龄为" << *p1.m_Age << endl;
//     cout << "p2的年龄为" << *p2.m_Age << endl;
// }
// int main()
// {
//     test01();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// // 关系运算符重载

// class Person
// {
// public:
//     Person(string name, int age)
//     {
//         m_Name = name;
//         m_Age = age;
//     }

//     string m_Name;
//     int m_Age;
//     // 重载关系运算符
//     bool operator==(Person &p)
//     {
//         if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
//         {
//             return true;
//         }
//         return false;
//     }
// };
// void test01()
// {
//     Person p1("Tom", 18);
//     Person p2("Tom", 8);
//     if (p1 == p2)
//     {
//         cout << "p1=p2" << endl;
//     }
//     else
//     {
//         cout << "p1!=p2" << endl;
//     }
// }
// int main()
// {
//     test01();
//     return 0;
// }

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
    // 匿名函数对象
    cout << MyAdd()(100,100) << endl;
    cout << ret << endl;
}
int main()
{
    test01();
    test02();
    return 0;
}