#include <iostream>

// دي المكتبة: مجرد دالة حسابية مستقلة

// this libaray has a one function calculate the taxes

double calculateTax(double price)
{
    return price * 0.14; // ضريبة 14%
}

int main()
{
    std::cout << "-- start: we prepare the bill ---\n";

    double productPrice = 100.0;

    // أنت المدير: أنت اللي حددت تستدعي الفانكشن هنا بالظبط
    double tax = calculateTax(productPrice);

    double total = productPrice + tax;
    std::cout << "Total: " << total << "\n";
    std::cout << "-- The Bill Printed ---\n";

    return 0;
}
