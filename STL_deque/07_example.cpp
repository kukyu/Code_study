#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<ctime>
// #### 3.4.1 案例描述

// 有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。

// #### 3.4.2 实现步骤

// 1. 创建五名选手，放到vector中
// 2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
// 3. sort算法对deque容器中分数排序，去除最高和最低分
// 4. deque容器遍历一遍，累加总分
// 5. 获取平均分

class Person
{
public:
    Person(string name, int score)
    {
        this->mName = name;
        this->mScore = score;
    }
    string mName; //姓名
    int mScore; // 平均分
};
void CreatPerson(vector<Person> &v)
{
    string nameSeed = "ABCDE";
    for (int i=0; i<5; i++)
    {
        string name = "选手";
        name += nameSeed[i];

        int score = 0;
        Person p(name, score);
        // 将创建的对象放入容器中
        v.push_back(p);
    }
}
void SetScore(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        deque<int> d;
        for(int i=0; i<10; i++)
        {
            int score = rand() % 41 + 60; // 60-100
            d.push_back(score);
        }

        // cout << "选手：" << it->mName << endl << "打分:" << " ";
        // for(deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        // {
        //     cout << *dit  << " ";
        // }
        // cout << endl;
        //排序
        sort(d.begin(), d.end());

        //去除最高最低分
        d.pop_back();
        d.pop_front();

        //取平均分
        int sum = 0;
        for(deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += *dit;
        }
        int avg = sum / d.size();
        // 平均分赋值到选手身上
        it->mScore = avg;

    }
}
void ShowScore(vector<Person> &v)
{
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << it->mName << " " << "平均分:" << it->mScore << endl;
    }

}
int main()
{
    // 随机数种子
    srand((unsigned int)time(NULL));
    // 1.创建五名选手
    vector<Person> v;
    CreatPerson(v);

    
    // 测试
    // for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout << "姓名：" << (*it).mName << "分数：" << (*it).mScore << endl; 
    // }
    // 2.打分
    SetScore(v);
    ShowScore(v);
    
    return 0;

}