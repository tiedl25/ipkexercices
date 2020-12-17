#include <iostream>
#include <cassert>

#include "include/canvas.hh"

//Test for Class Canvas
int main()
{
    int horPixels = 1000;
    int vertPixels = 1000;
    int height = 10;
    int width = 10;

    Canvas canvas(Point(0, 0), height, width, horPixels, vertPixels);

    assert((canvas.coord(0, 0).getX() == -5 && canvas.coord(0, 0).getY() == -5));
    assert((canvas.coord(horPixels-1, 0).getX() == 4.99 && canvas.coord(horPixels-1, 0).getY() == -5));
    assert((canvas.coord(0, vertPixels-1).getX() == -5 && canvas.coord(0, vertPixels-1).getY() == 4.99));
    assert((canvas.coord(horPixels-1, vertPixels-1).getX() == 4.99 && canvas.coord(horPixels-1, vertPixels-1).getY() == 4.99));
    
    return 0;
}