#pragma once
#include "../Item.h"
#include <iostream>
class Drink : public Item {
protected:
	bool _isCarbonated;
public:

	Drink(std::string name, std::string description, int price,
		int quantity, std::string size, bool isCarbonated)
		: Item(name, description, price, quantity, size), _isCarbonated(isCarbonated) {
	}

	// Constructor de copiere

	Drink(const Drink& other) : Item(other), _isCarbonated(other._isCarbonated){}

	// Operator =
	Drink& operator=(const Drink& other) {
		if (this == &other) return *this;
		Item::operator=(other);
		_isCarbonated = other._isCarbonated;
		return *this;
	}

	bool isCarbonated() const { return _isCarbonated; }

	void Display() const override {
		Item::Display();
		std::cout << " | Carbogazoasa: " << (_isCarbonated ? "da" : "nu") << "\n";
	}
};