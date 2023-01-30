#include<iostream>
using namespace std;
//函数模板注意事项
//1.数据类型一致T
template<class T> //class可以替换typename
void MySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
void test01()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	//MySwap(a, c); //类型不一样
	
	cout << "a=" << a << "\tb=" << b << endl;
}
//2.模板必须确定T的数据类型
template<typename T> 
void func()
{
	cout << "func调用" << endl;
}
void test02()
{
	func<int>();
}
int main()
{
	// test01();
	test02();
	system("pause");
	return 0;
}