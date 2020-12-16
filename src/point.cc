#include "include/point.hh"

    Point::Point() : _x(0), _y(0){}
    Point::Point(double x, double y) : _x(x), _y(y){}
    
    double Point::getX() const
    {
        return _x;
    }

    double Point::getY() const
    {
        return _y;
    }

    Point::~Point(){}