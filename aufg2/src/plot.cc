#include <cmath>
#include <algorithm>

#include "include/canvas.hh"

int main()
{
    Canvas canvas(Point(0, 0), 4, 3, 4000, 3000);

    for(int i=0; i<4000; i++)
    { 
        for(int j=0; j<3000; j++)
        {
            canvas.setBrightness(i, j, std::max(0.0, 100*((sin(std::pow(canvas.coord(i, j).getX(), -1)))*(sin(std::pow(canvas.coord(i, j).getY(), -1))))+1));
        }
    }

    canvas.write("canvas");

    return 0;
}