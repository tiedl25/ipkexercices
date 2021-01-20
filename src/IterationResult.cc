#include "include/IterationResult.hh"


IterationResult::IterationResult()
: _point(Point(0, 0)), _iterations(0){};

IterationResult::IterationResult(Point point, int iterations) 
: _point(point), _iterations(iterations){}

Point IterationResult::getPoint()
{
    return _point;
}
float IterationResult::getIterations()
{
    return _iterations;
}

void IterationResult::setPoint(Point &point)
{
    _point = point;
}
void IterationResult::setIterations(float iterations)
{
    _iterations = iterations;
}

IterationResult::~IterationResult(){}