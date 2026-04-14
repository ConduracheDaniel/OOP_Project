#pragma once
#include <string>
class IMenuItem
{
public:
	virtual std::string GetName() const = 0;
	virtual std::string GetDescription() const = 0;
	virtual int GetPrice() const = 0;
	virtual std::string GetSize() const = 0;
	virtual int GetQuantity() const = 0;
	virtual void Display() const = 0;

	virtual ~IMenuItem() = default;

};

