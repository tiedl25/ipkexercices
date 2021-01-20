#ifndef POINT_HH
#define POINT_HH

class Point
{
    private:
        double _x, _y;

    public: 
        Point();
        Point(double x, double y);
        ~Point();

        double getX() const;
        double getY() const;
};

#endif //POINT_HH