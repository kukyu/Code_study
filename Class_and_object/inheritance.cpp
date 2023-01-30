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

// #include <iostream>
// using namespace std;

// class Base
// {
// public:
//     int m_A;
// protected:
//     int m_B;
// private:
//     int m_C;
// };

// class Son : public Base
// {
//     // 父类中所有非静态成员属性都会被继承
// public:
//     int m_D;
// };

// void test01()
// {
//     cout << "size of Son =" << sizeof(Son) << endl;
// }

// int main()
// {
//     test01();
//     return 0;
// }
// #include <iostream>
// using namespace std;
// class Base
// {
// public:
//     Base()
//     {
//         cout << "Base构造函数!" << endl;
//     }
//     ~Base()
//     {
//         cout << "Base析构函数！" << endl;
//     }
// };
// class Son : public Base
// {
// public:
//     Son()
//     {
//         cout << "Son函数!" << endl;
//     }
//     ~Son()
//     {
//         cout << "Son析构函数！" << endl;
//     }
// };
// void test01()
// {
//     // Base b;
//     Son s;
// }
// int main()
// {
//     test01();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// // 继承中同名函数处理方式
// class Base
// {
// public:
//     Base()
//     {
//         m_A = 100;
//     }
//     void func()
//     {
//         cout << "Base - func()调用" << endl;
//     }
//     void func(int a)
//     {
//         cout << "Base - func(int a)调用" << endl;
//     }

//     int m_A;

// };
// class Son : public Base
// {
// public:
//     Son()
//     {
//        m_A = 200;
//     }
//     void func()
//     {
//         cout << "Son - func()调用" << endl;
//     }
//     int m_A;
// };
// void test01()
// {
//     Son s;
//     cout << "m_A="<< s.m_A << endl; // 访问子类
//     cout << "Base m_A = " << s.Base::m_A << endl; // 访问父类 加作用域
// }
// void test02()
// {
//     Son s;
//     s.func();
//     s.Base::func();//同名函数加作用域
//     // s.func(100); // 如果子类出现父类同名的成员函数，子类会隐藏父类所有的同名函数
//     s.Base::func(100);// 若访问 需要加作用域
// }
// int main()
// {
//     // test01();
//     test02();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// // 继承中静态同名函数处理方式
// class Base
// {
// public:
//     static int m_A;
// };
// int Base::m_A = 100;
// class Son : public Base
// {
// public:
//     static int m_A;
// };
// int Son::m_A = 200;
// // 同名静态成员属性
// void test01()
// {
//     // 1.通过对象访问
//     Son s;
//     cout << "Son m_A=" << s.m_A << endl;          // 访问子类
//     cout << "Base m_A = " << s.Base::m_A << endl; // 访问父类 加作用域
//     // 2.通过类名访问
//     cout << "类名访问Son:m_A=" << Son::m_A << endl;
//     // cout << "类名访问Base:m_A= " << Base::m_A << endl;
//     cout << "类名访问Base:m_A= " << Son::Base::m_A << endl; // 通过类名的方式访问父类作用域下

// }

// int main()
// {
//     test01();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// // 多继承语法
// class Base1
// {
// public:
//     Base1()
//     {
//         m_A = 100;  
//     }
//     int m_A;
// };
// class Base2
// {
// public:
//     Base2()
//     {
//         m_A = 200;  
//     }
//     int m_A;
// };

// class Son : public Base1, publicBase2
// {
// public:
//     Son()
//     {
//         m_C = 300;
//         m_D = 400;
//     }

//     int m_C;
//     int m_D;

// };
// void test01()
// {
//     Son s;
//     cout << "size of son = " << sizeof(s) << endl; 
//     cout << "Base1 m_A = " << s.Base1::m_A << endl;     
//     cout << "Base2 m_A = " << s.Base2::m_A << endl;    
// }
// int main()
// {
//     test01();
//     return 0;
// }

#include <iostream>
using namespace std;
// 菱形继承
// 动物类
class Animal
{
public:
    int m_Age;
};
//羊类
class Sheep : virtual public Animal{}; //利用虚继承解决这种问题
// Animal 虚基类

//骆驼
class Tuo : virtual public Animal{};
// 羊驼类
class SheepTuo : public Sheep, public Tuo{};

void test01()
{
    SheepTuo st;
    st.Sheep::m_Age = 18; 
    st.Tuo::m_Age = 28; 
    // 菱形继承加以作用域区分
    cout << "Sheep_m_Age = " << st.Sheep::m_Age << endl;   
    cout << "Tuo_m_Age = " << st.Tuo::m_Age << endl;
    // 菱形数据有两份 ，造成资源浪费 利用虚继承解决这种问题  
}
int main()
{
    test01();
    return 0;
}