#pragma once
#include "../../Coffee/Coffee.h"

class Capucino : public Coffee {
public:
    Capucino(int quantity, std::string size)
        : Coffee("Capucino", "Espresso cu spuma de lapte",
            15, quantity, size, "medium", true) {
    }

};