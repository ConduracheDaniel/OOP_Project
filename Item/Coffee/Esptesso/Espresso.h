#pragma once
#include "../../Coffee/Coffee.h"

class Espresso : public Coffee {
public:
    Espresso(int quantity, Size size)
        : Coffee("espresso", "Cafea neagra concentrata",
            10, quantity, size, "dark", false) {
    }

};