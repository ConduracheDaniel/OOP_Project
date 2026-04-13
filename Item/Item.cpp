#include "Item.h"
#include <iostream>


void Item::Display() const {
    std::cout << "[" << itemID << "] " << name
        << " x" << quantity
        << " (" << size << ")"
        << " - " << price << " RON\n";
}

