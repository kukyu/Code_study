#include<iostream>
using namespace std;
// 纯虚函数和抽象类
class Base
{
public:
    // 纯虚函数
    // 只要有一个纯虚函数 这个类称为抽象类
    // 抽象类特点: 1.无法实例化对象 2.抽象类的子类 必须重写父类的纯虚函数 否则也是抽象类
    virtual void fun() = 0;
};
// 子类
class Son : public Base
{
public:
    void fun()
    {
        cout << "小猫在说话" << endl;
    }
};
void test01()
{
    Son s;
    s.fun();
}

int main()
{
    test01();
    return 0;
}