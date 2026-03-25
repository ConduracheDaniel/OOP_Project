#pragma once
#include <string>
#include"../../User/User.h"
#include"../IMenuItem/IMenuItem.h"

class ICommand
{
private:
	std::string name;
	std::string description;
public:
	ICommand(std::string name, std::string description) : name(name), description(description) {};
	virtual std::string GetName() const = 0;
	virtual void SetName(const std::string& name) = 0;
	std::string GetDescription() { return description; }

	virtual void Execute(User user, IMenuItem& item) = 0;
};

