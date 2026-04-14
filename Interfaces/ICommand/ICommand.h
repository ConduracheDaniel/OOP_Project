#pragma once
#include <string>
#include "../IMenuItem/IMenuItem.h"

class Order;

class ICommand
{
public:
	virtual std::string GetName() const = 0;
	virtual std::string GetDescription() const = 0;
	virtual void Execute(IMenuItem* item, Order& order) = 0;

	virtual ~ICommand() = default;
};

