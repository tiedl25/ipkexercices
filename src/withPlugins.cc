#include <iostream>
#include <map>
#include <unordered_map>
#include "include/Frequencysource.hh"
#include "include/Frequencies.hh"
#include "include/Filter.hh"
#include "include/AnalysisPlugin.hh"

int main()
{
    using type = std::string;

    //define type of map to be used (at the beginning of the program)
    using WordMap = std::unordered_map<type,int>;

    //create custom word filtter (exercise b)
    Filter<type> filter;

    //create main class
    Frequencies<WordMap, Filter<type>> frequencies(filter);

    //add plugin of type PrintTotalCount<Map>
    frequencies.addPlugin(std::make_shared<PrintFrequencies<WordMap>>());
    frequencies.addPlugin(std::make_shared<PrintTotalCount<WordMap>>());

    //add source(Char or String)
    auto source = streamWordSource(std::cin);
    frequencies.readData(source);
    frequencies.printStatistics();

    return 0;
}