#ifndef BODY_HH
#define BODY_HH

#include <array>

#include "point.hh"

class Body
{
    public:
        Body(Point position, Point velocity, double mass, std::array<int, 3> colour);
        ~Body();

        Point getPosition();
        std::array<int, 3> getColour();
        Point getVelocity();
        double getMass();

        void setPosition(Point& p);
        void setVelocity(Point& v);
    private:
        Point _position;
        Point _velocity;
        double _mass;
        std::array<int, 3> _colour;
};

#endif