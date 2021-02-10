#ifndef POINT_HH
#define POINT_HH

class Point
{
    public:
        Point();
        Point(double x, double y);
        ~Point();

        double getX();
        double getY();
        void setX(double x);
        void setY(double y);

        Point operator+(Point& point);
        Point operator-(Point& point);
        Point operator+=(Point& point);
        Point operator-=(Point& point);
        Point operator*=(double factor);

        friend Point operator*(Point& point, double factor);
        friend Point operator*(double factor, Point& point);
    private:
        double _x;
        double _y;
};

#endif