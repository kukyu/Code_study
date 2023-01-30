# pragma once
#include<iostream>
using namespace std;
#include "point.h"

class Circle
{
    // 设置公共属性 从私有中拿出
public:
    // 设置半径
    void setR(int r);
    // 获取半径
    int getR();
    // 设置圆心
    void setCenter(Point center);
    // 获取圆心
    Point getCenter();
private:
    //属性
    // 半径
    int m_R;
    // 圆心
    Point m_Center;
};