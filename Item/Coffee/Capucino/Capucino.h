 #pragma once
#include "../../Coffee/Coffee.h"

class Capucino : public Coffee {
public:
    Capucino(int quantity, Size size)
        : Coffee("capucino", "Espresso cu spuma de lapte",
            15, quantity, size, "medium", true) {
    }

};