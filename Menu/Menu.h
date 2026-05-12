#pragma once
#include <set>
#include <string>
#include "../Item/Coffee/Americano/Americano.h"
#include "../Item/Coffee/Capucino/Capucino.h"
#include "../Item/Coffee/Esptesso/Espresso.h"
#include "../Item/Coffee/Latte/Latte.h"
#include "../Item/Drinks/OrangeJuice/OrangeJuice.h"
#include "../Item/Drinks/Water/SparklingWater.h"

class Menu {
private:
	static Menu* instance;
	std::set<std::string> availableItems;

	Menu();
public:
	Menu(const Menu&) = delete;
	Menu& operator=(const Menu&) = delete;

	static Menu* GetInstance();
	const std::set<std::string>& GetAvailableItems()const { return availableItems; }
	bool Contains(const string& name)const;
	void Display()const;
};