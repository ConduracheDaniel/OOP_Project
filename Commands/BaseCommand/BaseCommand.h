#pragma once
#include "../../Interfaces/ICommand/ICommand.h"
#include <vector>

class BaseCommand : public ICommand {
protected:
	std::string name;
	std::string description;
public:
    BaseCommand(std::string name, std::string description)
        : name(name), description(description) {
    }

    std::string GetName() const override { return name; }
    std::string GetDescription() const override { return description; }

    virtual void Execute(const std::vector<std::string>& tokens, Order& order) = 0;
};