#include "../Drinks.h"

class OrangeJuice : public Drink {
public:
	OrangeJuice(int quantity, Size size)
		: Drink("orangeJuice", "Suc de portocale natural", 12, quantity, size, false) {
	}

	// Constructor Copiere
	OrangeJuice(const OrangeJuice& other) : Drink(other) {}

	// Operator =
	OrangeJuice& operator=(const OrangeJuice& other) {
		if (this == &other) return *this;
		Drink::operator=(other);
		return *this;
	}
};