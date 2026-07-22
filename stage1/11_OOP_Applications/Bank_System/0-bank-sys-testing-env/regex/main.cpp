#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::string email = "user@example.com";
    std::cout << "Email Valid: " << std::boolalpha << isValidEmail(email) << "\n";
}
