#include <iostream>
using namespace std;

// 模板不是万能的

class Person
{
public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    string name;
    int age;
};
// 对比两个数据是否相等
template <typename T>
bool MyCompare(T &a, T &b)
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 利用具体化的Person的版本来实现代码，具体化优先调用
template <>
bool MyCompare(Person &p1, Person &p2)
{
    if (p1.name == p2.name && p1.age == p2.age)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void test01()
{
    int a = 10;
    int b = 20;
    bool ret = MyCompare(a, b);
    if (ret)
    {
        cout << "a=b" << endl;
    }
    else
    {
        cout << "a!=b" << endl;
    }
}
void test02()
{
    Person p1("Tom", 10);
    Person p2("Tom", 10);
    bool ret = MyCompare(p1, p2);
    if (ret)
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
    system("cls");
    // test01();
    test02();
    return 0;
}