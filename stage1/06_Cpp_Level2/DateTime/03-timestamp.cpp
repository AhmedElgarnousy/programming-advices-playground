#include <iostream>

#include <ctime>

int main()
{
    // get the current timestamp
    time_t prev_timestamp = time(0);

    while (1)
    {
        // printed by rate of change to timestamp which is 1 sec
        while (prev_timestamp != time(0))
        {
            std::cout << "prev timestamp: " << prev_timestamp << "\n";
            prev_timestamp = time(0);
            std::cout << "current timestamp: " << prev_timestamp << "\n";
        }
    }

    return 0;
}