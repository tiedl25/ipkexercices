#ifndef ITERATIONRESULT_HH
#define ITERATIONRESULT_HH

#include "point.hh"

class IterationResult
{
    public:
        IterationResult();
        IterationResult(Point point, int iterations);

        Point getPoint();
        double getIterations();

        void setPoint(Point &point);
        void setIterations(double iterations);

        

        ~IterationResult();
    private:
        Point _point;
        double _iterations;

};

#endif