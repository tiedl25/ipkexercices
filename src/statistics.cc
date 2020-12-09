#include <algorithm>
#include <cmath>

#include "include/statistics.hh"



double mean(const std::vector<double>& v)
{
    if(v.size() == 0)
        return 0;
    double mid = (double)v[0];
    for(long unsigned int i=1; i<v.size(); i++)
    {
        mid += v[i];
    }

    return mid/v.size();
}

double median(const std::vector<double>& v)
{
    if(v.size() == 0)
        return 0;
    std::vector<double> vSorted = v;
    std::sort(vSorted.begin(), vSorted.end());

    if(vSorted.size() == 0)
    {
        return 0;
    } 
    else if(vSorted.size()%2 != 0)
    {
        return v[(vSorted.size()+1)/2-1];
    }  
    else
    {
        return v[0.5*((vSorted.size())/2 + (vSorted.size()/2) + 1)-1]; 
    }
}

double moment(const std::vector<double>& v, int k)
{
    double mid = (double)v[0];
    double potence = 0;
    for(double i : v)
    {
        potence = i;
        for(int j=0; j<k; j++)
        {
            potence *= i;
        }
        mid += potence;
    }

    return mid/v.size();
}

double standard_deviation(const std::vector<double>& v)
{
    double mid = mean(v);
    double variance = (v[0] - mid) * (v[0] - mid);
    for(long unsigned int i=1; i<v.size(); i++) 
    {
        variance += (v[i] - mid) * (v[i] - mid);
    }

    return std::pow(variance/v.size(), 0.5);
}




