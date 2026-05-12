#pragma once
#include "../../Coffee/Coffee.h"

class Americano : public Coffee {
private:
public:
    static const string ClassName;
    Americano(int quantity, Size size)
        : Coffee(ClassName, "Espresso diluat cu apa calda",
            12, quantity, size, "medium", false) {
    }

};
