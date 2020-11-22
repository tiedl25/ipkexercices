#include <iostream>
#include <cmath>

double root_iterative(double q, int n, int steps)
{
    double result = 1;
    double cache;
    double quot = n;
    for (int j=1; j<steps; j++)
    {
        cache = result;
        for (int i=1; i<n-1; i++)
        {
            
            result *= cache;
        }

        result = cache + 1/quot * (q/result - cache);
    }


    return result;
}

void test_root(double q, int n, int steps)
{
    double potence = root_iterative(q, n, steps);
    double cache = potence;

    for (int i=1; i<n; i++)
    {
        potence *= cache;
    }

    q = round(q);
    potence = round (potence);
    
    std::cout << "Potenz: " << potence << std::endl;
    std::cout << "q: " << q << std::endl;
    std::cout << "n: " << n << std::endl;
    std::cout << "steps: " << steps << std::endl;
    std::cout << "q-a^n: " << q - potence << std::endl;
}

int main()
{
    int n;
    double q;
    int steps;

    std::cout << "n: ";
    std::cin >> n;

    std::cout << "q: ";
    std::cin >> q;

    std::cout << "Please enter steps: ";
    std::cin >> steps;

    if (n == 0)
    {
        std::cout << "Durch 0 teilen funktioniert nicht..." << std::endl;
        return 0;
    }

    /*std::cout << "Ergebnis: " << root_iterative(q, n, steps) << std::endl;
    double quot = n;
    std::cout << "Kontroll Ergebnis: " << std::pow(q, 1/quot) << std::endl;*/

    test_root(q, n, steps);

    return 0;
}