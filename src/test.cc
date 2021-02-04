#include <iostream>
#include <map>
#include <unordered_map>
#include "include/Letterfrequencies.hh"

int main()
{
    Letterfrequencies<std::map<char, int>> frequencies;
    auto source = streamLetterSource(std::cin);
  
    frequencies.readData(source);
    
    frequencies.printStatistics();

    return 0;
}