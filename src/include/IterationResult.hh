#ifndef ITERATIONRESULT_HH
#define ITERATIONRESULT_HH

#include "point.hh"

class IterationResult
{
    public:
        IterationResult();
        IterationResult(Point point, int iterations);

        Point getPoint();
        float getIterations();

        void setPoint(Point &point);
        void setIterations(float iterations);

        

        ~IterationResult();
    private:
        Point _point;
        float _iterations;

};

#endif