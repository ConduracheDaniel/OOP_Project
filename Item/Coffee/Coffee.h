#pragma once
#include "../Item.h"
#include <iostream>
class Coffee : public Item {
protected:
    bool hasMilk;

public:
    Coffee(std::string name, std::string description, int price,
        int quantity, Size size,
        std::string roast, bool hasMilk)
        : Item(name, description, price, quantity, size), hasMilk(hasMilk) {
    }

    bool HasMilk() const { return hasMilk; }

    void Display() const override {
        Item::Display();
        std::cout << " | Lapte: " << (hasMilk ? "da" : "nu") << "\n";
    }
};