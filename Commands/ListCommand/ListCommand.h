#pragma once
#include "../BaseCommand/BaseCommand.h"

class ListCommand : public BaseCommand {
public:
    ListCommand() : BaseCommand("list", "Afiseaza produsele din comanda") {}
    void Execute(const std::vector<std::string>& tokens, Order& order) override;
};
