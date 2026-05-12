#pragma once
#include "../../Coffee/Coffee.h"

class Capucino : public Coffee {
    
public:
    static const string ClassName;
    Capucino(int quantity, Size size)
        : Coffee(ClassName, "Espresso cu spuma de lapte",
            15, quantity, size, "medium", true) {
    }

};
