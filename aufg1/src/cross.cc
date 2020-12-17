#include <vector>
#include <cmath>
#include <iostream>

#include "include/polygon.hh"

int main()
{
    const double pi=M_PI;

    std::vector<Point> points;
    points.push_back(Point{0, 2});
    points.push_back(Point{2, 2});
    points.push_back(Point{2, 4});
    points.push_back(Point{0, 0});
    points.push_back(Point{-2, 0});
    Polygon polygon = Polygon{points};

    std::cout << polygon.volume() << std::endl;
    
    return 0;
}