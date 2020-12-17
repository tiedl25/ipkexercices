#include "include/canvas.hh"

//Initilization for Class Canvas
Canvas::Canvas(const Point& center, double width, double height, int horPixels, int vertPixels)
: _mid(center), _horPixels(horPixels), _vertPixels(vertPixels), _height(height), _width(width), _pixels(_horPixels, std::vector<int>(_vertPixels)){}

int Canvas::brightness(int i, int j) const
{
    return _pixels[i][j];
}

void Canvas::setBrightness(int i, int j, int brightness)
{
    _pixels[i][j] = brightness;
}

Point Canvas::coord(int i, int j) const
{
    return Point(_mid.getX() - _width/2 + _width/_horPixels * i, _mid.getY() - _height/2 + _height/_vertPixels * j);
}

void Canvas::write(const std::string& filename)
{
    write_pgm(_pixels, filename);
}

Canvas::~Canvas(){}
//End of Initilization