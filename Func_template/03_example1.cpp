#include <iostream>
using namespace std;
/*
排序模板
从大到小
测试char数组、int数组
*/
// 交换函数模板
template <typename T>
void MySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void MySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[max] < arr[j])
            {
                max = j;
            }
        }
        if (max != i)
        {
            MySwap(arr[max], arr[i]); // 交换
        }
    }
}

// 打印数组模板
template <typename T>
void PrintArray(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void test01()
{
    // 测试char数组
    char charArr[] = "basdfgh";
    int num = sizeof(charArr) / sizeof(char);
    MySort(charArr, num);
    PrintArray(charArr, num);
}
void test02()
{
    // 测试int数组
    int intArr[] = {1, 2, 3, 5, 9, 7, 5, 3, 4, 2, 7};
    int num = sizeof(intArr) / sizeof(int);
    MySort(intArr, num);
    PrintArray(intArr, num);
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}