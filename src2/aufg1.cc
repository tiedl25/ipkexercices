#include <iostream>
#include <cmath>

void midnight(double a, double b, double c)
{
    double zero1, zero2;

    std::cout << "Eingegebene Formel: " << a << "x²+" << b << "x+" << c << "=0" << std::endl;

    zero1 = (-b + std::sqrt(b * b - 4 * a * c)) / (2 * a);
    zero2 = (-b - std::sqrt(b * b - 4 * a * c)) / (2 * a);

    std::cout << "Nullstelle 1: " << zero1 << std::endl;
    std::cout << "Nullstelle 2: " << zero2 << std::endl;

    return;
}

int main()
{
    double a=0;
    double b=0;
    double c=0;

    std::cout << "### Dieses Programm berechnet die Mitternachtsformel" << std::endl;
    std::cout << "### Dafür geben sie bitte nacheinander die Koeffizienten a, b, c an\n" << std::endl;

    while((a==b && a==0) || (b*b - 4*a*c) < 0)
   {
        std::cout << "a: ";
        std::cin >> a;
        std::cout << "b: ";
        std::cin >> b;
        std::cout << "c: ";
        std::cin >> c;

        if (a == b && a==0)
            std::cout << "Keine Eindeutige Lösung, da a=b=0. Bitte andere Zahlen wählen\n";

        if ((b*b - 4*a*c) < 0)
            std::cout << "Lösung nicht darstellbar. Bitte andere Zahlen wählen\n";
    }

    midnight(a, b, c);

    return 0;
}

