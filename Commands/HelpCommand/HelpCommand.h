#pragma once
#include "../BaseCommand/BaseCommand.h"
#include "../../Item/Item.h"
#include <vector>

class HelpCommand : public BaseCommand{
private:
    const std::vector<ICommand*>& commands;
public:
    HelpCommand(const std::vector<ICommand*>& commands) : BaseCommand("help","Afiseaza toate comenzile disponibile"), commands(commands) {}
    void Execute(const vector<string>& tokens,Order& order) override;

};
