#pragma once
#include <string>
#include "../IMenuItem/IMenuItem.h"
#include <vector>

class Order;

class ICommand
{
public:
	virtual std::string GetName() const = 0;
	virtual std::string GetDescription() const = 0;
	virtual void Execute(const std::vector<std::string>& tokens, Order& order) = 0;

	virtual ~ICommand() = default;
};

