#include "include/point.hh"

Point::Point() : _x(0), _y(0) {}

Point::Point(double x, double y) : _x(x), _y(y) {}

Point::~Point(){}

double Point::getX()
{
    return _x;
}

double Point::getY()
{
    return _y;
}

void Point::setX(double x)
{
    _x = x;
}

void Point::setY(double y)
{
    _y = y;
}

Point Point::operator+(Point& point)
{
    return Point(_x + point.getX(), _y + point.getY());
}

Point Point::operator-(Point& point)
{
    return Point(_x - point.getX(), _y - point.getY());
}

Point Point::operator+=(Point& point)
{
    return *this + point;
}

Point Point::operator-=(Point& point)
{
    return *this - point;
}

Point Point::operator*=(double factor)
{
    return *this * factor;
}

Point operator*(Point& point, double factor)
{
    return Point(point.getX()*factor, point.getY()*factor);
}

Point operator*(double factor, Point& point)
{
    return Point(point.getX()*factor, point.getY()*factor);
}