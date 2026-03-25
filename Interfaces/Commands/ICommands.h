#pragma once
#include <string>
class ICommands
{
private:
	std::string name;
	std::string description;
public:
	ICommands(std::string name, std::string description) : name(name), description(description) {}
	virtual void Execute() = 0;
	std::string GetName() { return name; }
	std::string GetDescription() { return description; }
};

