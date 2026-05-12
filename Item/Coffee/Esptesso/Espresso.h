#pragma once
#include "../../Coffee/Coffee.h"

class Espresso : public Coffee {
public:
    static const string ClassName;
    Espresso(int quantity, Size size)
        : Coffee(ClassName, "Cafea neagra concentrata",
            10, quantity, size, "dark", false) {
    }

};
