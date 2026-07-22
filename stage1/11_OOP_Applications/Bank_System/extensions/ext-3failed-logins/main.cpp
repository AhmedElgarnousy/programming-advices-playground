
#include "clsLoginScreen.h"

int main()
{
    while (1)
    {
        clsLoginScreen::enLoginRetStatus res = clsLoginScreen::ShowLoginScreen();
        if (res == clsLoginScreen::enLoginRetStatus::eLocked)
        {
            break;
        }
    }

    return 0;
}