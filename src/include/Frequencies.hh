#ifndef FREQUENCIES_HH
#define FREQUENCIES_HH

#include <iostream>
#include <memory>

#include "Frequencysource.hh"
#include "Filter.hh"
#include "AnalysisPlugin.hh"


template<typename Map, typename Filter>
class Frequencies 
{
    public:
        Frequencies(Filter filter) : _filter(filter){}
        ~Frequencies(){}

        //abstract Plugin base type
        using Plugin = AnalysisPlugin<Map>;

        //add a new plugin
        void addPlugin(const std::shared_ptr<Plugin> plugin)
        {
            _plugins.push_back(plugin);
        }

        //Processes all letters obtained from source
        template<typename Source>
        void readData(Source& source)
        {
            //auto source = streamLetterSource(std::cin);
            
            while (true)
            {
                auto data = source.next();
                if (not data.second)
                    break;
                // work with letter in data.first
                auto next = _filter.transform(data.first);
                _letterMap[next] += 1;
            }
            
        }

        // does the statistics and prints to stdout
        void printStatistics()
        {
            for (auto& plugin : _plugins)
            {
                std::cout << "\nPlugin: " << plugin->name() << std::endl;
                plugin->printStatistics(_letterMap);
            }
                
        }

    private:
        Map _letterMap;
        Filter _filter; 
        typedef typename Map::key_type type;

        std::vector<std::shared_ptr<Plugin>> _plugins;

};

#endif