
#include "clsMainScreen.h"
#include "clsUser.h"

#include "clsUtil.h"
#include "clsString.h"

int main()
{
    // clsMainScreen::ShowMainMenu();

    clsUser user1("mohamed", "kamal", "alemail", "elphone879789", "honda", "582010");

    user1.WriteLinetoFile();

    return 0;
}