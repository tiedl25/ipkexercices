#include <iostream>

long int fibonacci(int number)
{
    long int fib1=0;
    long int fib2=1;
    long int sum=0;

    for (int i=1; i<=number; i++)
    {
        if (i > 2)
        {
            sum = fib1 + fib2;
            fib1 = fib2;
            fib2 = sum;
            
            std::cout << "Number " << i << ": " << sum << std::endl;
        }
        else if(i == 1)
            std::cout << "Number " << i << ": " << 0 << std::endl;
        else if(i == 2)
            std::cout << "Number " << i << ": " << 1 << std::endl;
    }

    return sum;
}

int main ()
{
    long int number;

    std::cout << "Please enter a number: ";
    std::cin >> number;

    number = fibonacci(number);

    //std::cout << "Result: " << number << std::endl;

    return 0;
}