#pragma once
#include <iostream>

using std::string;

class clsString
{
private:
    string _Value;

public:
    clsString()
    {
        _Value = "";
    }
    clsString(string value)
    {
        _Value = value;
    }

    void SetValue(const string value)
    {
        _Value = value;
    }
    string Value() const
    {
        return _Value;
    }

    static int CountWords(string str)
    {
        int wordCount = 0;

        // Step 1: Clean up any leading spaces so we don't count an empty word
        while (!str.empty() && str.find(' ') == 0)
        {
            str.erase(0, 1);
        }

        // Step 2: Loop to process and erase words one by one
        while (!str.empty())
        {
            size_t spacePos = str.find(' ');

            if (spacePos == std::string::npos)
            {
                // No more spaces found; the remaining string is the last word
                wordCount++;
                break;
            }

            // A space was found; erase the word and the space itself
            wordCount++;
            str.erase(0, spacePos + 1);

            // Step 3: Handle multiple consecutive spaces by erasing extra spaces
            while (!str.empty() && str.find(' ') == 0)
            {
                str.erase(0, 1);
            }
        }

        return wordCount;
    }

    int CountWords()
    {
        return CountWords(_Value);
    }
};