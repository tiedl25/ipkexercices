#ifndef ANALYSISPLUGIN_HH
#define ANALYSISPLUGIN_HH

template<typename Map>
class AnalysisPlugin
{
    public:
        using Data = typename Map::key_type;

        //always add virtual destructor
        ~AnalysisPlugin(){}

        //returns the name of the plugin
        virtual std::string name() const = 0;

        //does some statistics on the map and prints it to stdout
        virtual void printStatistics(const Map& map)
        {
            //do nothing by default
        }
};

template<typename Map>
class PrintFrequencies : public AnalysisPlugin<Map>
{
    public: 
        virtual std::string name() const override
        {
            return "PrintFrequencies";
        }

        virtual void printStatistics(const Map& map) override
        {
            int counter=0;
            for(auto&c : map)
            {
                counter += c.second;
            }
            for(auto& c : map)
            {
                std::cout << "Letter/Word " << c.first << " Number:\t" << c.second << "\t\tPercentage: "<< c.second/(double)counter*100 << "%" << std::endl;
            }       
        }
};

template<typename Map>
class PrintTotalCount : public AnalysisPlugin<Map>
{
    public:
        virtual std::string name() const override
        {
            return "PrintTotalCount";
        }

        virtual void printStatistics(const Map& map) override
        {
            int counter=0;
            for(auto&c : map)
            {
                counter += c.second;
            }
            std::cout << "Total Number: " << counter << std::endl; 
        }
};

#endif