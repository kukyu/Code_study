#include <iostream>
using namespace std;
#include <string>
// 类模板
template <class NameType, class AgeType = int> // 默认参数

class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->mName = name;
        this->mAge = age;
    }
    void showPerson()
    {
        cout << "name: " << this->mName << " age: " << this->mAge << endl;
    }
    NameType mName;
    AgeType mAge;
};
// 1.类模板没有自动类型推导使用方式
void test01()
{
    // Person p("100", 1000);
    Person<string, int> p("11", 1000);
    p.showPerson();
    Person<string> p2("111", 111);  // 默认参数
    p2.showPerson();
}
int main()

{
    test01();
    return 0;
}