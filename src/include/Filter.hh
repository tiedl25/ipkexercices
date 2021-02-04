#ifndef FILTER_HH
#define FILTER_HH

#include "Frequencysource.hh"
#include <vector>


template<typename Data>
class Filter 
{
    public:

        Filter(){}
        ~Filter(){}

        // decides whether the input letter or word should be
        // removed from the statistics (not added to the map)

        bool remove(const Data& data)
        {
            return 0;
        }
};

template<>
class Filter <char> 
{
    public:
        // takes the input data and returns a transformed
        // version (e.g. capitalizes all letters)
        char transform(const char& data)
        {
            char c = std::toupper(data);
            if(!std::isalpha(c)) return '0';
            return c;
        }
};

template<>
class Filter <std::string> 
{
    public:
        // takes the input data and returns a transformed
        // version (e.g. capitalizes all letters)
        std::string transform (const std::string& data)
        {
            std::string dataTransformed = data;
            for(int i=0; i<data.length(); ++i)
            {
                if(std::isalpha(data.at(i)) != 0) continue;
                dataTransformed.push_back(std::toupper(data.at(i)));
            }
            return dataTransformed;
        }
};



#endif