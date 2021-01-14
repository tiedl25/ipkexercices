#include <iostream>
#include <vector>

#include "include/io.hh"
#include "include/statistics.hh"

int main()
{
    std::vector<double> result = read_vector(); 
    std::cout << mean(result) << std::endl;
    std::cout << median(result) << std::endl;
    std::cout << moment(result, 3) << std::endl;
    std::cout << standard_deviation(result) << std::endl;
    /*for (double i : result)
        std::cout << i << std::endl;*/
    return 0;
}