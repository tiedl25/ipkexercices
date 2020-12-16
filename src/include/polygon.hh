#ifndef POLYGON_HH
#define POLYGON_HH

#include <vector>
#include <array>
#include "point.hh"

class Polygon
{
    public:
        Polygon(const std::vector<Point>& corners);
        Polygon(const std::vector<double>& x, const std::vector<double>& y);

        std::size_t corners() const;
        const Point& corner(std::size_t i) const;
        double volume() const;

        ~Polygon();
    private:
        std::vector<Point> _corners;
};

#endif //POLYGON_HH