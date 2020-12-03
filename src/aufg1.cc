#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

//Funktionen
void aufg1a()
{
    std::vector<double> v1;
    std::vector<double> v2(10);
    std::vector<double> v3 = {{ 3, 8, 7, 5, 9, 2 }};

    for (int i=0; i<v1.size(); i++)
    {
        std::cout << v1[i] << std::endl;
    }
    for (int i=0; i<v2.size(); i++)
    {
        std::cout << v2[i] << std::endl;
    }
    for (int i=0; i<v3.size(); i++)
    {
        std::cout << v3[i] << std::endl;
    }
}


std::vector<double> reversed(const std::vector<double>& v)
{
    int vSize = v.size();
    std::vector<double> vReversed(vSize);
    
    for (int i=0; i<vSize; i++)
    {
        vReversed[i] = v[vSize-1-i];
    }

    return vReversed;
}

std::pair<int, int> minmax(std::vector<int>& vec)
{
    std::sort(vec.begin(), vec.end());
    return std::pair<int, int> (vec[0], vec[vec.size()-1]);
}

void roundVektor(std::vector<double>& vec)
{
    for(int i=0; i<vec.size(); i++)
    {
        vec[i] = std::round(vec[i]);
    }
}

void swapVector(std::vector<double>& vec)
{
    for (int i=0; i<vec.size()/2; i++)
    {
        std::swap(vec[i], vec[vec.size()-i-1]);
    }
}

int main()
{
    //aufg1a();

    
    std::vector<int> vec = {{ 4, 2, 6, 7, 3 , 345, 234, 122 , 0}};

    // Aufgabe 1b
    std::pair<int, int> minmaxPair = minmax(vec);
    std::cout << "Minimum: " << minmaxPair.first << std::endl;
    std::cout << "Maximum: " << minmaxPair.second << std::endl;

    std::vector<double> vec2 = {{ 2.4, 5, 23.3423, 4, 95, 234.34 , 7, 0}};

    // Aufgabe 1c
    vec2 = reversed(vec2);

    // Aufgabe 1d
    roundVektor(vec2);

    // Aufgabe 1e
    swapVector(vec2);

    // Zum testen von Aufgabe 1c/d
    for (int i=0; i<vec2.size(); i++)
    {
        std::cout << vec2[i] << std::endl;
    }

    return 0;
}

