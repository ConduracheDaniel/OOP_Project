#include "../../Drinks/Drinks.h"

class SparklingWater : public Drink {
public:
	static const string ClassName;
	SparklingWater(int quantity, Size size)
		: Drink(ClassName, "Apa cu bule", 4, quantity, size, true) {
	}

	// Constructor de copiere
	SparklingWater(const SparklingWater& other) : Drink(other){}

	// Operator =
	SparklingWater& operator=(const SparklingWater other) {
		if (this == &other) return *this;
		Drink::operator=(other);
		return *this;
	}
};
const string SparklingWater::ClassName = "sparklingWater";