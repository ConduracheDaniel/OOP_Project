#pragma once
#include "../../Coffee/Coffee.h"

class Americano : public Coffee {
public:
    Americano(int quantity, std::string size)
        : Coffee("Americano", "Espresso diluat cu apa calda",
            12, quantity, size, "medium", false) {
    }

};