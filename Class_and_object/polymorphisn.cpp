#include<iostream>
using namespace std;
# include <string>
// 虚析构和纯虚虚构
class Animal
{
public:
    Animal()
    {
        cout << "Anmial构造函数调用" << endl;
    }
    // virtual ~ Animal() // 利用虚析构可以解决父类指针释放子类对象时不干净的问题 
    // {
    //     cout << "Animal析构函数调用" << endl;
    // }
    // 纯虚虚构也可以解决上述问题 需要有声明 也要有实现
    virtual ~ Animal() = 0;
    // 纯虚函数
    virtual void speak() = 0;
};
Animal :: ~Animal()
{
    cout << "Animal纯虚析构函数调用" << endl; // 
}
// 子类
class Cat : public Animal
{
public:
    Cat(string name)
    {
        cout << "cat 构造函数调用" << endl;
        m_Name = new string(name);
    }
    virtual void speak()
    {
        cout << *m_Name << "小猫在说话" << endl;
    }
    ~Cat()
    {
        if(m_Name != NULL)
        {
            cout << "cat 析构函数调用" << endl;  // 不调用析构函数 导致内存泄漏
            delete m_Name;
            m_Name = NULL;
        }
    }
    string *m_Name;
};
void test01()
{
    Animal *animal = new Cat("Tom");
    animal -> speak();
    delete animal;
}

int main()
{
    test01();
    return 0;
}