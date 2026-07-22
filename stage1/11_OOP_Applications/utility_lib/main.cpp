#include <iostream>
#include "utility_lib/clsUtil.h"

int main()
{
    clsUtil::Srand();
    std::cout << clsUtil::RandomNumber(10, 15) << "\n";

    clsDate A = clsDate();
    clsDate B = clsDate(12, 8, 2027);

    A.Print();
    B.Print();

    clsUtil::Swap(A, B);

    A.Print();
    B.Print();

    std::string str1[30];
    clsUtil::FillArrayWithRandomWords(str1, 30, clsUtil::MixChars, 5);

    std::cout << clsUtil::DecryptText("mtyqpsm~z{��CBLsymux:o{y", 12) << "\n";

    std::cout << "Myname:" << clsUtil::Tabs(1) << "test\n";

    for (int i = 0; i < 10; i++)
        std::cout << str1[i] << " ";
    std::cout << "\n";

    clsUtil::ShuffleArray(str1, 30);

    for (int i = 0; i < 10; i++)
        std::cout << str1[i] << " ";
    std::cout << "\n";
    //-----------------------------

    //-----------------------------
    std::cout << clsUtil::GenerateWord(clsUtil::CapitalLetter, 10) << "\n";

    //-----------------------------
    clsUtil::GenerateKeys(5, clsUtil::MixChars);

    //-----------------------------
    std::cout << clsUtil::EncryptText("ahmedgarnousy76@gmail.com", 12) << "\n";

    //-----------------------------
    int myArr[10];
    clsUtil::FillArrayWithRandomNumbers(myArr, 10, 20, 35);

    for (int i = 0; i < 10; i++)
        std::cout << myArr[i] << " ";
    std::cout << "\n";

    //-----------------------------
    std::string myStr[50];
    clsUtil::FillArrayWithRandomWords(myStr, 50, clsUtil::CapitalLetter, 10);

    for (int i = 0; i < 10; i++)
        std::cout << myStr[i] << " ";
    std::cout << "\n";

    //-----------------------------
    std::cout << clsUtil::SmallLetter << "\n";

    return 0;
}