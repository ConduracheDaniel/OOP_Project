#pragma once
#include "../../Coffee/Coffee.h"

class Americano : public Coffee {
public:
    Americano(int quantity, Size size)
        : Coffee("americano", "Espresso diluat cu apa calda",
            12, quantity, size, "medium", false) {
    }

};