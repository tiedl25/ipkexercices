#include <iostream>

void collatz(int number)
{
    std::cout << number << std::endl;

    bool abort = 1;

    while (abort == 1)
    {
        if (number % 2 == 0)
            number /= 2;
        else
            number = number * 3 + 1;

        if (number == 1 || number == 0 || number == -1 || number == -5 || number == -17)
            abort = 0;
    }

    std::cout << number << std::endl;

    
        
    
}

int main()
{
    int number;

    std::cout << "Please enter a number: ";
    std::cin >> number;

    collatz(number);

    return 0;
}