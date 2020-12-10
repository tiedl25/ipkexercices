#include <iostream>
#include <cassert>
#include <cmath>

#include "include/statistics.hh"

int main()
{
    std::vector<double> testVector;
    assert(mean(testVector) == 0);
    assert(median(testVector) == 0);

    testVector = {5, 56.34, 17.4, 34};
    assert(std::abs(mean(testVector) - 28.185 < 1e-1));
    assert(std::abs(median(testVector) - 56.34 < 1e-1));

    testVector.push_back(3);
    assert(std::abs(mean(testVector) - 23.148 < 1e-1));
    assert(std::abs(median(testVector) - 17.4 < 1e-1));

    return 0;
}