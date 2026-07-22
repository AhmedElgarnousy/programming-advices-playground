#include <iostream>
#include <string>

#include "clsString.h"

int main()
{
    string text = "ahmed kamal hussin elgarnousy";

    std::cout << clsString::CountWords(text) << "\n";

    clsString string1;
    clsString string2("ahmed mohamed");

    string1.SetValue("mohand mohamed mostafa ");

    std::cout << string1.Value() << "\n";
    std::cout << string2.Value() << "\n";

    std::cout << "num of count words: " << string1.CountWords() << "\n";
    std::cout << "num of count words: " << string2.CountWords() << "\n";
    std::cout << "num of count words: " << string2.CountWords("word1 word2") << "\n";

    /*
     */

    return 0;
}