#ifndef POINT_HH
#define POINT_HH

#include <array>
#include <cmath>

template<typename Coord, int dim>
class Point
{
    private:
        std::array<Coord, dim> _Coordinate;

    public: 
        Point()
        {
            for(int i=0; i<dim; i++)
            {
                _Coordinate[i] = 0;
            }
        }
        Point(std::array<Coord, dim> Coordinate): _Coordinate(Coordinate){}

        static const int dimension = dim;

        ~Point(){}

        Coord& x(int i)
        {
            return _Coordinate[i];
        }

        double norm() const
        {
            double cache = 1;
            for(int i=0; i<dimension; i++)
            {
                cache *= _Coordinate[i] * _Coordinate[i];
            }
            return sqrt(cache);
        }

        Coord& operator[](int i)
        {
            return _Coordinate[i];
        }

        const Coord& operator[](int i) const
        {
            return _Coordinate[i];
        }
};     

#endif //POINT_HH