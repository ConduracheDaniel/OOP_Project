#pragma once
#include <string>
#include "../../User/User.h"
class IMenuItem
{
	private:
		std::string name;
		std::string description;
		int price;
		std::string itemID;
public:
	IMenuItem(std::string name, std::string description, int price, std::string itemID) : name(name), description(description), price(price), itemID(itemID) {}
	std::string GetName() { return name; }
	std::string GetDescription() { return description; }
	int GetPrice() const { return price; }
	std::string GetItemID() { return itemID; }
	virtual void Display() = 0;
	virtual void ProcessCommand(std::string input, User user) = 0;
	virtual std::string GetContextualHelp() = 0;
};

