// #include<iostream>
// using namespace std;
// // 成员变量和成员函数分开储存
// class Person
// {
//     int m_A; // 非静态成员变量,属于类对象上
//     static int m_B; //静态成员变量  不属于类对象上
//     void fun(){} //  非静态成员函数 不属于类对象上
//     static void func2(){} //静态成员函数 不属于类对象上

// };
// int Person :: m_B = 0; //初始化
// void test01()
// {
//     Person p;
//     // 空对象占用内存空间:1
//     // C++编译器给每个空对象也分配一个字节空间,区分空对象占内存的位置
//     // 空对象也应该有一个独一唯二的地址
//     cout << "size of p =" << sizeof(p) << endl;
// }
// void test02()
// {
//     Person p;
//     cout << "size of p =" << sizeof(p) << endl;
// }
// int main()
// {
//     // test01();
//     test02();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Person
// {
// public:
//     Person(int age)
//     {
//         // age = age; //名字冲突
//         this->age = age; // this 指针指向被调用成员函数所属的对象,谁调用指向谁
//     }
//     Person &PersonAddAge(Person &p)
//     {
//         this->age += p.age;
//         return *this; //  /*this 指向对象本体
//     }
//     int age;
// };
// // 1.解决名称冲突
// void test01()
// {
//     Person p1(18);
//     cout << "p1的年龄为:" << p1.age << endl;
// }
// // 2.返回队形本身用*this
// void test02()
// {
//     Person p1(10);
//     Person p2(13);
//     p2.PersonAddAge(p1).PersonAddAge(p1); // 链式编程
//     cout << "p2的年龄为:" << p2.age << endl;
// }
// int main()
// {
//     test01();
//     test02();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// // 空指针调用成员函数
// class Person
// {
// public:
//     void showClassName()
//     {
//         cout << "this is Person Class" << endl;
//     }
//     void showPersonAge()
//     {
//         // 报错原因是因为传入的指针为NULL
//         if (this == NULL)
//         {
//             return;
//         }
//         cout << "age = " << m_Age << endl;
//     }
//     int m_Age;
// };
// void test01()
// {
//     Person *p = NULL;
//     p->showClassName();
//     p->showPersonAge();
// }
// int main()
// {
//     test01();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// // 常函数
// class Person
// {
// public:
//     // this指针的本质 是指针常量 指针的指向是不可修改的
//     // 在成员函数后面加const ,修饰的是this指针指向 让指针指向的值不可以修改
//     void showPerson() const
//     {
//         // this->m_A = 100; //不可以修改
//         // this = NULL; //this 指针不可以修改指针指向
//         this->m_B = 100;
//         cout << m_B << endl;
//         cout << m_A << endl;
//     }
//     void func(){}

//     int m_A;
//     mutable int m_B; //加上关键字可以修改
// };
// void test01()
// {
//     Person p;
//     p.showPerson();
// }
// // 常对象
// void test02()
// {
//     const Person p; // 在对象前加const ,变为常对象
//     // p.m_A = 100;
//     p.m_B = 200;
//     cout << p.m_B << endl;
//     // 常对象只能调用常函数
//     p.showPerson();
//     p.func();// 不可调用
// }
// int main()
// {
//     // test01();
//     test02();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// #include <string.h>
// class Building
// {
//     // 友元可以访问私有
//     friend void goodGay(Building *building);
//     // 建筑物的类
// public:
//     Building()
//     {
//         m_SettingRoom = "客厅";
//         m_BedRoom = "卧室";
//     }

// public:
//     string m_SettingRoom; // 客厅
// private:
//     string m_BedRoom; // 卧室
// };
// // 全局函数
// void goodGay(Building *building)
// {
//     cout << "好基友全局函数 正在访问:" << building->m_SettingRoom << endl;
//     cout << "好基友全局函数 正在访问:" << building->m_BedRoom << endl; // 私有属性不可访问
// }
// void test01()
// {
//     Building building;
//     goodGay(&building);
// }
// int main()
// {
//     test01();
//     return 0;
// }

// #include <iostream>
// using namespace std;
// #include <string.h>
// class Building
// {
//     // 类做友元
//     friend class GoodGay;
// public:
//     Building();
// public:
//     string m_SettingRoom; //客厅
// private:
//     string m_BedRoom; // 卧室
// };
// // 类做友元
// class GoodGay
// {
// public:
//     GoodGay();
// public:
//     void visit(); //参观函数 访问building的属性
//     Building *building;
// };
// // 类外写成员函数
// Building::Building()
// {
//     m_SettingRoom = "客厅";
//     m_BedRoom = "卧室";
// }
// GoodGay::GoodGay()
// {
//     //创建建筑物的对象
//     building = new Building;
// }
// void GoodGay::visit()
// {
//     cout << "好基友类正在访问：" << building ->m_SettingRoom << endl;
//     cout << "好基友类正在访问：" << building ->m_BedRoom << endl;
// }
// void test01()
// {
//     GoodGay hh;
//     hh.visit();
// }
// int main()
// {
//     test01();
//     return 0;
// }

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