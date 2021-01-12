#include "include/point.hh"
#include <cassert>
#include <iostream>
#include <array>

int main()
{
    std::array<double, 3> arr = {1, 2, 3};
    Point<double, 3> point{arr};
    assert(point.norm() == 6);

    std::array<int, 1> arr2 = {5};
    Point<int, 1> point2{arr2};
    assert(point2.norm() == 5);

    return 0;
}
