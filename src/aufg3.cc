#include <iostream>
#include <cmath>

double root_iterative(double q, int n, int steps)
{
    double result = 1;
    double cache; //Variable als Zwischenspeicher

    if (n == 1 || q == 0)
    {
        return q;
    }

    double quot = n; //n als Double Variable um Rundungsfehler zu vermeiden

    //Berechnung n-te Wurzel
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

    //Wurzel wird potenziert um Ergebnis zu überprüfen
    for (int i=1; i<n; i++)
    {
        potence *= cache;
    }

    //Runden für genaue Ergebnisse
    q = round(q * 100000.0) / 100000.0;
    potence = round (potence * 100000.0) / 100000.0;

    //Ausgabe der Parameter
    std::cout << "q: " << q << std::endl;
    std::cout << "n: " << n << std::endl;
    std::cout << "steps: " << steps << std::endl;
    std::cout << "q-a^n: " << q - potence << std::endl;
}

int main()
{
    int n, steps;
    double q;

    //Benutzereingaben
    std::cout << "# Dieses Programm berechnet die n-te Wurzel einer positiven Zahl #" << std::endl;
    std::cout << "Wurzelexponent: ";
    std::cin >> n;
    std::cout << n << "-te Wurzel von: ";
    std::cin >> q;
    std::cout << "Anzahl der Durchläufe für eine verbesserte Genauigkeit: ";
    std::cin >> steps;

    if (n == 0)
    {
        std::cout << "Faktor muss größer als 0 sein." << std::endl;
    }
    else if(q < 0)
    {
        std::cout << "Wurzel muss positiv sein." << std::endl;
    }
    else
    {
        //Für Aufgabenteil A/B
        std::cout << "Ergebnis: " << root_iterative(q, n, steps) << std::endl;
        double quot = n;
        std::cout << "Kontroll Ergebnis: " << std::pow(q, 1/quot) << std::endl;

        //Für Aufgabenteil C
        test_root(q, n, steps);
    }


    return 0;
}