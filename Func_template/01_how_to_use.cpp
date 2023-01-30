#include<iostream>
using namespace std;
//函数模板
//两个整型交换函数
void SwapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//交换浮点型函数
void SwapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//函数模板
template<typename T> //声明 T通用的数据类型
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
	//SwapInt(a, b);
	// 使用模板
	//1.自动类型推导
	//MySwap(a, b);
	//2.显示指定类型
	MySwap<int>(a, b);
	cout << "a=" << a << "\tb=" << b << endl;
}
void test02()
{
	double c = 10.4;
	double d = 20.5;
	//SwapDouble(c, d);
	MySwap(c, d);
	cout << "c=" << c << "\td=" << d << endl;
}
int main()
{
	test01();
	test02();
	system("pause");
}