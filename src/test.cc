#include "include/polygon.hh"
#include <cassert>
#include <vector>
#include <cmath>
#include <iostream>

//#define M_PI 3.14159265358979323846

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
            
            if(0 - sin(j/i*2*pi) < 1e-10)
                pointY = 0;

            if(0 - cos(j/i*2*pi) < 1e-10)
                pointX = 0;   
         
            Point point = Point{pointX, pointY}; 
            points.push_back(point);
            //std::cout << point.getX() << "\t" << point.getY() << std::endl;
        }
        polygons.push_back(points);
    }
    
    std::cout << polygons[3].volume() << std::endl;

    //assert(4 - (polygons[3].volume()) < 1e-10);
    return 0;
}