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