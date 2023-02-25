#include <iostream>
using namespace std;
// * map中所有元素都是pair
// * pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
// * 所有元素都会根据元素的键值自动排序
// map和multimap**区别**：

// - map不允许容器中有重复key值元素
// - multimap允许容器中有重复key值元素

#include <map>

void printMap(map<int,int>&m)  //写两个
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}

void test01()
{
	map<int,int>m; //默认构造
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	printMap(m);

	map<int, int>m2(m); //拷贝构造
	printMap(m2);

	map<int, int>m3;
	m3 = m2; //赋值
	printMap(m3);
}

int main() {

	test01();

	// system("pause");

	return 0;
}