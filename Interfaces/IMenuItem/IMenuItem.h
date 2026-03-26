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

	virtual std::string GetName() = 0;

	virtual std::string GetDescription() = 0;

	virtual int GetPrice() = 0;

	virtual std::string GetItemID() = 0;


	virtual void Display() = 0;

	virtual void ProcessCommand(std::string input, User user) = 0;

	virtual std::string GetContextualHelp() = 0;
};

