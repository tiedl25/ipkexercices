#ifndef LETTERFREQUENCIES_HH
#define LETTERFREQUENCIES_HH

#include "Frequencysource.hh"

template<typename Map>
class Letterfrequencies 
{
    public:
        Letterfrequencies(){};
        ~Letterfrequencies(){};
        //Processes all letters obtained from source
        template<typename Source>
        void readData(Source& source)
        {
            while (true)
            {
              auto data = source.next();
              if (not data.second)
                break;
              // work with letter in data.first
              if(!std::isalpha(data.first)) continue;
              _letterMap[std::toupper(data.first)] += 1;
            }
        }

        // does the statistics and prints to stdout
        void printStatistics()
        {
            double counter=0;
            for(auto& c : _letterMap)
            {
                counter += c.second;
            }
            for(auto& c : _letterMap)
            {
                std::cout << "Buchstabe " << c.first << " Anzahl: " << c.second << "\tAnteil: "<< c.second/counter*100 << "%" << std::endl;
            }

            std::cout << "Gesamtanzahl Buchstaben: " << counter << std::endl;
        }

    private:
        Map _letterMap;

};

#endif