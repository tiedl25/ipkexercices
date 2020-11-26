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
                q *= cache;
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
        else if (n > 0)
            return q * recursive(q, n - 1);
    }

    int improved(int base, int expo)
    {
        if(expo == 0)
        {
            return 1;
        }
        else if(expo == 1)
        {
            return base;
        }

        if(expo % 2 == 0)
        {
            base = improved(base, expo/2);
            base *= base;
            
        }
        else
        {
            base *= improved(base, expo-1);
        }
        return base;
    }
}

int main()
{
    int base, expo, choice;

    std::cout << "# Dieses Programm berechnet Potenzen, dazu bitte zunächst die Basis und im nächsten Schritt einen positiven Exponenten angeben #\n" << std::endl;
    std::cout << "Basis: ";
    std::cin >> base;
    std::cout << "Exponent: ";
    std::cin >> expo;

    if (expo < 0)
    {
        std::cout << "Exponent muss positiv sein." << std::endl;
        return 0;
    }

    std::cout << "Soll das Ergebnis Iterativ(0), Rekursiv(1), oder Verbessert(2) berechnet werden?" << std::endl;
    std::cin >> choice;

    if (choice == 0)
        std::cout << "Iterativ berechnetes Ergebnis: " << power::iterative(base, expo) << std::endl;
    else if (choice == 1)
        std::cout << "Rekursiv berechnetes Ergebnis: " << power::recursive(base, expo) << std::endl;
    else if (choice ==2)
        std::cout << "Ergebnis verbesserte Berechnung: " << power::improved(base, expo) << std::endl;
    else    
        std::cout << "Eingabe nicht zutreffend";

    return 0;
}