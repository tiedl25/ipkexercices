#include <iostream>
#include "include/io.hh"
#include "include/statistics.hh"

int main ()
{
    std::vector<double> result = uniform_distribution(random_seed(), 10000000, 5.7, 53.7);
    std::cout << mean(result) << std::endl;
    std::cout << median(result) << std::endl;
    std::cout << moment(result, 1) << std::endl;
    std::cout << standard_deviation(result) << std::endl;
    /*for (double i : result)
        std::cout << i << std::endl;*/
    return 0;
}