#include <iostream>
#include <cassert>

#include "include/statistics.hh"

int main()
{
    std::vector<double> testVector;
    assert(mean(testVector) == 0);
    assert(median(testVector) == 0);

    testVector = {5, 56, 17, 34};
    assert(mean(testVector) == 28);
    assert(median(testVector) == 56);

    testVector.push_back(3);
    assert(mean(testVector) == 23);
    assert(median(testVector) == 17);

    return 0;
}