#pragma once
#include <iostream>
#include "../../Interfaces/ICommand/ICommand.h"
#include "../../User/User.h"
#include "../../Item/Item.h"
class HelpCommand : public ICommand{
private:
    std::string _name = "help";
public:
    std::string GetName() const override { return _name; }
    void SetName(const std::string& name) override { _name = name; }

    void Execute(User& user, Item& item);

};

