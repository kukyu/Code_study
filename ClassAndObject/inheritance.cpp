// #include <iostream>
// using namespace std;

// // class Java
// // {
// // public:
// //     void header()
// //     {
// //         cout << "首页、公开课、登录、注册...(公共头部)" << endl;
// //     }
// //     void footer()
// //     {
// //         cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
// //     }
// //     void left()
// //     {
// //         cout << "Java、Python、C++...(公共分类列表)" << endl;
// //     }
// //     void content()
// //     {
// //         cout << "Java学科视频" << endl;
// //     }

// // };
// // class Python
// // {
// // public:
// //     void header()
// //     {
// //         cout << "首页、公开课、登录、注册...(公共头部)" << endl;
// //     }
// //     void footer()
// //     {
// //         cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
// //     }
// //     void left()
// //     {
// //         cout << "Java、Python、C++...(公共分类列表)" << endl;
// //     }
// //     void content()
// //     {
// //         cout << "Python学科视频" << endl;
// //     }
// // };
// // class Cpp
// // {
// // public:
// //     void header()
// //     {
// //         cout << "首页、公开课、登录、注册...(公共头部)" << endl;
// //     }
// //     void footer()
// //     {
// //         cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
// //     }
// //     void left()
// //     {
// //         cout << "Java、Python、C++...(公共分类列表)" << endl;
// //     }
// //     void content()
// //     {
// //         cout << "C++学科视频" << endl;
// //     }
// // };
// // 继承好处 减少代码重复
// // 语法：class 子类 ：继承方式 父类
// // 子类 也称派生类
// // 父类 也称为基类
// // 继承实现页面
// class BasePage
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
// };
// class Java : public BasePage
// {
// public:
//     void content()
//     {
//         cout << "Java学科视频" << endl;
//     }
// };
// class Python : public BasePage
// {
// public:
//     void content()
//     {
//         cout << "Python学科视频" << endl;
//     }
// };
// void test01()
// {
//     cout << "Java下载视频页面如下" << endl;
//     Java ja;
//     ja.header();
//     ja.footer();
//     ja.left();
//     ja.content();
//     cout << "-----------------------------" << endl;
//     cout << "Python下载视频页面如下" << endl;
//     Python py;
//     py.header();
//     py.footer();
//     py.left();
//     py.content();
//     cout << "-----------------------------" << endl;
//     cout << "C++下载视频页面如下" << endl;
// }
// int main()
// {
//     test01();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Base1
// {
// public:
//     int m_A;
// protected:
//     int m_B;
// private:
//     int m_C; 
// };

// class Son1 : public Base1
// {
//     void func()
//     {
//         m_A = 10; // 父类公共权限内容到子类依然是公共权限
//         m_B = 10; // 父类保护权限到子类依然是保护权限
//         // m_C = 10; // 私有权限不可访问
//     }
// };
// class Base2
// {
// public:
//     int m_A;
// protected:
//     int m_B;
// private:
//     int m_C; 
// };
// class Son2 : protected Base2
// {
//     void func()
//     {
//         m_A = 10; // 父类公共权限内容到子类变为保护权限
//         m_B = 10; // 父类保护权限到子类依然是保护权限
//         // m_C = 10; // 私有权限不可访问
//     }
// };
// class Base3
// {
// public:
//     int m_A;
// protected:
//     int m_B;
// private:
//     int m_C; 
// };
// class Son3 : private Base3
// {
// public:
//     void func()
//     {
//         m_A = 100; //父类公共成员到子类变为私有权限
//         m_B = 100; //父类保护成员到子类变为私有权限
//         // m_C = 100; // 私有变量访问不到
//     }

// };
// void test01()
// {
//     Son1 s1;
//     s1.m_A = 100;
//     // s1.m_B = 100; // 类外访问不到保护权限

// }
// void test02()
// {
//     Son2 s1;
//     // s1.m_A = 100; // 类外访问不到保护权限
//     // s1.m_B = 100; // 类外访问不到保护权限
// }
// void test03()
// {
//     Son3 s1;
//     // s1.m_A = 100; // 类外访问不到私有权限
//     // s1.m_B = 100; // 类外访问不到私有权限
// }

// int main()
// {
//     test01();
//     return 0;
// }

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