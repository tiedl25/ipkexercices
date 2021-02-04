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
            return std::toupper(data);
        }

        bool remove(const char& data)
        {
            if(!std::isalpha(data)) return true;
            return false;
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
            std::string dataTransformed;
            for(int i=0; i<data.length(); ++i)
            {
                dataTransformed.push_back(std::toupper(data.at(i)));
            }
            return dataTransformed;
        }

        bool remove(const std::string& data)
        {
            for(int i=0; i<data.length(); ++i)
            {
                if(!std::isalpha(data.at(i))) return true;
            }
            return false;
        }
};



#endif