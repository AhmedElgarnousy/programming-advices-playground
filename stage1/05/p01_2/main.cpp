#include <iostream>

void print_header()
{
    std::cout << "\n\n\t\t\tMultiplication Table From 1 to 10\n\n";

    for (int i = 1; i <= 10; i++)
    {
        std::cout << "\t" << i;
    }
    std::cout << "\n\n";
    std::cout << "-----------------------------------------------------------------------------------\n";
}

void print_mutli_10x_table()
{
    print_header();
    for (int i = 1; i <= 10; i++)
    {
        if (i == 10)
        {
            std::cout << i << "   |  ";
            // BS ASCII t is used to move the cursor or print head back one position, effectively deleting the previous character.
            std::cout << (char)8; // or \b
        }
        else
        {
            std::cout << i << "    |  ";
        }

        for (int j = 1; j <= 10; j++)
        {
            std::cout << i * j << "\t";
        }
        std::cout << "\n";
    }
}
int main()
{
    print_mutli_10x_table();

    return 0;
}