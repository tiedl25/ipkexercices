#include <iostream>

#include "include/frequencies.hh"

std::map<char, int> get_frequencies()
{
    std::map<char, int> letterMap;

    while (true)
    {
        unsigned char c;
        // read in character
        std::cin >> c;
        // abort if input closed
        c = toupper(c);

        if (not std::cin)
            break;
        // work with c
        // PUT YOUR CODE THAT PROCESSES c HERE

        if(!isalpha(c))
            continue;
        letterMap[c] = letterMap[c]+1;
    }
    return letterMap;
}

void print_frequencies(const std::map<char, int>& frequencies)
{
    double counter=0;
    for(auto& c : frequencies)
    {
        counter += c.second;
    }
    for(auto& c : frequencies)
    {
        std::cout << "Buchstabe " << c.first << " Anzahl: " << c.second << "\tAnteil: "<< c.second/counter*100 << "%" << std::endl;
    }

    std::cout << "Gesamtanzahl Buchstaben: " << counter << std::endl;
}
