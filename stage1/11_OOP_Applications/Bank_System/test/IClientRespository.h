
#pragma once

#include "clsBankClient.h"
class IClientRepository
{

private:
public:
    virtual vector<clsBankClient> LoadDB() = 0;
};
