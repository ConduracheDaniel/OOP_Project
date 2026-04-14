#pragma once
#include "../../Interfaces/ICommand/ICommand.h"


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

    virtual void Execute(IMenuItem* item, Order& order) = 0;
};