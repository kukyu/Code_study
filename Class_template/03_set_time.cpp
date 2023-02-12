#include <iostream>
using namespace std;
#include <string>

class Person1
{
public:
	void ShowPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:
	void ShowPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template <class T>
class MyClass
{
public:
	T obj;

	// 类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成

	void fun1() { obj.ShowPerson1(); }
	void fun2() { obj.ShowPerson2(); }
};

void test01()
{
	MyClass<Person1> m;

	m.fun1();

	// m.fun2();//编译会出错，说明函数调用才会去创建成员函数
}

int main()
{

	test01();

	// system("pause");

	return 0;
}