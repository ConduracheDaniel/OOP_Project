#pragma once
#include "../../Coffee/Coffee.h"

class Latte : public Coffee {
public:
    static const string ClassName;
    Latte(int quantity, Size size)
        : Coffee(ClassName, "Espresso cu mult lapte",
            17, quantity, size, "light", true) {
    }

};
