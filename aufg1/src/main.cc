#include <vector>
#include <cmath>
#include <iostream>

#include "include/polygon.hh"

int main()
{
    std::vector<Polygon> polygons;
    const double pi=M_PI;

    for(double i=1; i<=10; i++)
    {
        std::vector<Point> points;
        for(double j=1; j<=i; j++)
        {
            double pointX = cos(j/i*2*pi);
            double pointY = sin(j/i*2*pi);
         
            Point point = Point{pointX, pointY}; 
            points.push_back(point);
        }
        polygons.push_back(points);
        std::cout << polygons[i-1].volume()<< std::endl;
    }

    return 0;
}