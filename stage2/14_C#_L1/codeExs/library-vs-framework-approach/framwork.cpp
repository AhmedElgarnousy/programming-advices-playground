#include <iostream>
#include <functional> // عشان نستخدم std::function

// ده إطار العمل (الفريم ورك)
class BillingEngine
{
private:
    // مكان بنشيل فيه الفانكشن بتاعتك (Extension Point)
    std::function<double(double)> taxCallback;

public:
    // الإطار بيقولك: "لو سمحت سجل الفانكشن بتاعتك هنا"
    void registerTaxCalculator(std::function<double(double)> callback)
    {
        taxCallback = callback;
    }

    // الإطار هو اللي سايق دورة حياة البرنامج بالكامل
    void run()
    {
        std::cout << "[Framework] system starts and read the data...\n";
        double price = 100.0;

        // إطار العمل بيتشيك لو أنت باعتله كود يشغله
        double tax = 0.0;
        if (taxCallback)
        {
            // مبدأ هوليوود: الإطار هو اللي بينادي كودك هنا!
            tax = taxCallback(price);
        }

        std::cout << "[Framework] Total Price: " << (price + tax) << "\n";
        std::cout << "[Framework]  Process done and saved .\n";
    }
};

// --- كودك أنت بقى كمبرمج ---
double myEgyptTax(double price)
{
    return price * 0.14;
}

int main()
{
    BillingEngine framework;

    // بنسجل الفانكشن بتاعتنا جوا الإطار (مش بنشغلها بنفسنا)

    // we register our function inside the framwork does't call it by us

    framework.registerTaxCalculator(myEgyptTax);

    // بنقول للإطار: "ادور أنت بقى واشتغل"

    // say to framwork go and run my app

    framework.run();

    return 0;
}
