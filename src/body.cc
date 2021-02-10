#include "include/body.hh"

Body::Body(Point position, Point velocity, double mass, std::array<int, 3> colour)
: _position(position), _velocity(velocity), _mass(mass), _colour(colour){}

Body::~Body(){}

Point Body::getPosition()
{
    return _position;
}

void Body::setPosition(Point& p)
{
    _position = p;
}

std::array<int, 3> Body::getColour()
{
    return _colour;
}

Point Body::getVelocity()
{
    return _velocity;
}

void Body::setVelocity(Point& v)
{
    _velocity = v;
}

double Body::getMass()
{
    return _mass;
}