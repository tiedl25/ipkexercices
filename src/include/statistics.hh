#ifndef STATISTICSS_HH 
#define STATISCTICS_HH

#include <vector>
#include <algorithm>
#include <cmath>

template<typename T>
double mean(const T& v)
{
    if(v.size() == 0)
        return 0;
    double mid = v[0];
    for(long unsigned int i=1; i<v.size(); i++)
    {
        mid += v[i];
    }

    return mid/v.size();
}

template<typename T>
double median(const T& v)
{
    std::vector<double> vSorted = v;
    std::sort(vSorted.begin(), vSorted.end());

    if(vSorted.size() == 0)
    {
        return 0;
    } 
    else if(vSorted.size()%2 != 0)
    {
        return vSorted[(v.size()+1)/2-1];
    }  
    else
    {
        return vSorted[0.5*((v.size())/2 + (v.size()/2) + 1)-1]; 
    }
}

template<typename T>
double robust_median(const T& v)
{
    if(v.size() == 0)
        return 0;

    std::vector<typename T::value_type> vSorted;
    //vSorted.resize(v.size()); //funktioniert nicht
    std::copy(v.begin(), v.end(), std::back_inserter(vSorted));
    std::sort(vSorted.begin(), vSorted.end());

    if(vSorted.size()%2 != 0)
    {   
        return vSorted[(v.size()+1)/2-1]; //ungerade Zahlen
    }  
    else
    {
        return vSorted[0.5*((v.size())/2 + (v.size()/2) + 1)-1]; //gerade Zahlen
    }
}

template<typename T>
double moment(const T& v, int k)
{
    double mid = 0;
    double potence = 0;
    for(double i : v)
    {
        potence = i;
        for(int j=0; j<k-1; j++)
        {
            potence *= i;
        }
        mid += potence;
    }

    return mid/v.size();
}

template<typename T>
double standard_deviation(const T& v)
{
    double mid = mean(v);
    double variance = (v[0] - mid) * (v[0] - mid);
    for(long unsigned int i=1; i<v.size(); i++) 
    {
        variance += (v[i] - mid) * (v[i] - mid);
    }

    return std::pow(variance/v.size(), 0.5);
}


#endif //STATISCTICS_HH