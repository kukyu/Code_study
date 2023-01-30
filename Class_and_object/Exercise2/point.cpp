#include "point.h"
//设置x
void Point::setX(int x) //作用域下的函数
{
    m_X = x;
}
// 设置y
void Point::setY(int y)
{
    m_Y = y;
}
//获取x
int Point::getX()
{
    return m_X;
}
//获取y
int Point::getY()
{
    return m_Y;
}
