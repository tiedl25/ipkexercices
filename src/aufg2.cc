#include <iostream>

namespace power
{
    int iterative(int q, int n)
    {
        int cache = q;
        if(n > 0)
        {
            for (int i=1; i<n; i++)
            {
                q*=cache;
            }
        }
        else
            q = 1;

        return q;
    }

    int recursive(int q, int n)
    {
        
        
        if (n==0)
            return 1;
        n--;    
        if (n > 0)
            q *= recursive(q, n);
        
        
    }
}


int main()
{
    int base, expo;

    std::cout << "Dieses Programm berechnet Potenzen, dazu bitte zunächst die Basis und im nächsten Schritt den Exponenten angeben.\n" << std::endl;
    std::cout << "Bitte eine Basis angeben: ";
    std::cin >> base;
    std::cout << "Bitten einen Exponeneten angeben: ";
    std::cin >> expo;

    if (expo < 0)
    {
        std::cout << "Exponent muss positiv sein." << std::endl;
        return 0;
    }

    std::cout << "Iterativ berechnetes Ergebnis: " << power::iterative(base, expo) << std::endl;
    std::cout << "Rekursiv berechnetes Ergebnis: " << power::recursive(base, expo) << std::endl;

    return 0;
}