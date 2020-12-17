#include "include/polygon.hh"

//Initilization for Class Polygon
Polygon::Polygon(const std::vector<Point>& corners) : _corners(corners) {}

Polygon::Polygon(const std::vector<double>& x, const std::vector<double>& y)
{
    for(int i=0; i<x.size(); i++)
    {
        Point point(x[i], y[i]);
        _corners.push_back(point);
    }
    
}

std::size_t Polygon::corners() const
{
    return _corners.size();
}

const Point& Polygon::corner(std::size_t i) const
{
    return _corners[i];
}

double Polygon::volume() const
{
    if(_corners.size() <= 2)
        return 0;
        
    double volume=0;
    for(int i=0; i<_corners.size(); i++)
    {
        int i1 = i+1;
        if(i==_corners.size()-1)
            i1=0;
        volume += (_corners[i].getX() * (_corners[i1].getY()) - (_corners[i1].getX()) * _corners[i].getY());
    }
    return volume/2;
}

Polygon::~Polygon(){}
//End of Initilization