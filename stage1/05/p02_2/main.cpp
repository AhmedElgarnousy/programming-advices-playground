#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

bool isPrime(int num)
{
    if (num <= 1)
        return false; // 0 , 1 are not prime
    if (num == 2)
        return true; // 2 is prime
    if (num % 2 == 0)
        return false; // all even > 2 are not prime

    // check odd divisorsup to sqrt(n)
    for (int i = 3; i <= std::sqrt(num); i += 2)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

void prime_test()
{
    int num{};
    while (1)
    {
        system("clear");
        std::cin >> num;
        std::cout << num << ":";
        getchar();
        std::cout << isPrime(num);
    }
}

void printAllPrimeNums(int num)
{
    for (int i = 0; i <= num; i++)
    {
        if (isPrime(i))
            std::cout << i << " ";
    }
    std::cout << "\n";
}

int main()
{
    int num{};
    std::cin >> num;
    printAllPrimeNums(num);

    return 0;
}