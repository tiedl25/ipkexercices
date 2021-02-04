#include <iostream>
#include <map>
#include <fstream>
#include "include/Letterfrequencies.hh"

int main(int argc, char* argv[])
{
    Letterfrequencies<std::map<char, int>> frequencies{};
    for(int i=1; i<argc; ++i)
    {
        std::ifstream f(argv[i]);
        auto source = streamLetterSource(f);
        frequencies.readData(source);
    }
    
  
    
    frequencies.printStatistics();

    return 0;
}