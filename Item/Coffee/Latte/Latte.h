#pragma once
#include "../../Coffee/Coffee.h"

class Latte : public Coffee {
public:
    Latte(int quantity, std::string size)
        : Coffee("Latte", "Espresso cu mult lapte",
            17, quantity, size, "light", true) {
    }

};