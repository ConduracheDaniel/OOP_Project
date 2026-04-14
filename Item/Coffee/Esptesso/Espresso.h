#pragma once
#include "../../Coffee/Coffee.h"

class Espresso : public Coffee {
public:
    Espresso(int quantity, std::string size)
        : Coffee("Espresso", "Cafea neagra concentrata",
            10, quantity, size, "dark", false) {
    }

};