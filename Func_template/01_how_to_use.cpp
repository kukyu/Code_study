#include<iostream>
using namespace std;
//����ģ��
//�������ͽ�������
void SwapInt(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//���������ͺ���
void SwapDouble(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//����ģ��
template<typename T> //���� Tͨ�õ���������
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
	// ʹ��ģ��
	//1.�Զ������Ƶ�
	//MySwap(a, b);
	//2.��ʾָ������
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