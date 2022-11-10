#include<iostream>
using namespace std;
#include "point.h"
#include "circle.h"
void isInCircle(Circle &c, Point &p)
{
    //计算两点之间距离的平方
    int distance = (c.getCenter().getX() - p.getX()) ^ 2 + (c.getCenter().getY() - p.getY()) ^ 2;
    // 计算半径的平方
    int rDistance = c.getR() ^ 2;
    if (distance == rDistance)
    {
        cout << "点在圆上" << endl;
    }
    else if (distance > rDistance)
    {
        cout << "点在圆外" << endl;
    }
    else
    {
        cout << "点在圆内" << endl;
    }
}
int main()
{
    //实例化
    //创建一个圆
    Circle c1;
    c1.setR(10);
    Point p1;
    p1.setX(0);
    p1.setY(0);
    c1.setCenter(p1);
    //创建一个点
    Point p2;
    p2.setX(0);
    p2.setY(10);
    //判断关系
    isInCircle(c1, p2);
    return 0;
}