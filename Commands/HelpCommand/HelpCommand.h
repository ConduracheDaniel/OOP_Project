#pragma once
#include <iostream>
#include "../../Interfaces/ICommand/ICommand.h"
#include "../../Item/Item.h"
class HelpCommand : public ICommand{
private:
    std::string _name = "help";
    std::string _description = "inforamtii help.";
public:
    std::string GetName() const override { return _name; }
    void SetName(const std::string& name) override { _name = name; }

    std::string GetDescription() { return _description; }
    void SetDescription(const std::string& description)override { _description = description; }

    void Execute(IMenuItem& item) override;

};
