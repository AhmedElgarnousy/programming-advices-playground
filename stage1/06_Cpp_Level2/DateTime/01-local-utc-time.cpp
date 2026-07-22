#include <iostream>
#include <ctime>

int main()
{
    time_t time_now = time(0);
    std::cout << "Timestamp     : " << time_now << "\n";

    // local time string
    char *dt = ctime(&time_now);
    std::cout << "Local time    : " << dt; // ctime adds \n already

    // UTC struct
    tm *gmtm = gmtime(&time_now);

    std::cout << "Day           : " << gmtm->tm_mday << "\n";
    std::cout << "Month         : " << gmtm->tm_mon + 1 << "\n";     // +1
    std::cout << "Year          : " << gmtm->tm_year + 1900 << "\n"; // +1900
    std::cout << "Weekday (0=Sun): " << gmtm->tm_wday << "\n";

    // UTC time string
    std::cout << "UTC time      : " << asctime(gmtm); // asctime adds \n

    return 0;
}