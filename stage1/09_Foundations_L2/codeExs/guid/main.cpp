// https://github.com/mariusbancila/stduuid
#include "uuid.h"
#include <iostream>

int main()
{
    std::mt19937 rng(std::random_device{}());

    uuids::uuid_random_generator gen{rng};

    auto id = uuids::to_string(gen());
    std::cout << id << "\n";
}
// → "f47ac10b-58cc-4372-a567-0e02b2c3d479"