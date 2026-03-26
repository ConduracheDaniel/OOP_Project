#pragma once
#include <iostream>
#include "../../Interfaces/ICommand/ICommand.h"
#include "../../User/User.h"
#include "../../Item/Item.h"
class HelpCommand : public ICommand{
private:
    std::string _name = "help";
    std::string _description = "Displays help inforamtion.";
public:
    std::string GetName() const override { return _name; }
    void SetName(const std::string& name) override { _name = name; }

    std::string GetDescription() { return _description; }
    void SetDescription(const std::string& description)override { _description = description; }

    void Execute(User user, IMenuItem& item) override;

};
