#ifndef CANVAS_HH
#define CANVAS_HH

#include <vector>
#include <string>

#include "point.hh"
#include "pgm.hh"

class Canvas
{
    private:
        const int _horPixels, _vertPixels;
        const Point _mid;
        const double _height, _width;
        std::vector<std::vector<int>> _pixels;

    public:
        Canvas(const Point& center, double width, double height, int horPixels, int vertPixels);
        ~Canvas();

        double brightness(int i, int j) const;
        void setBrightness(int i, int j, double brightness);
        int getHor();
        int getVert();
        Point coord(int i, int j) const;
        Point Coord(int i, int j) const;
        void write(const std::string& filename); 
};

#endif //CANVAS_HH