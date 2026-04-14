#pragma once
#include "../BaseCommand/BaseCommand.h"

class ListCommand : public BaseCommand {
public:
    ListCommand() : BaseCommand("list", "Afiseaza produsele din comanda") {}
    void Execute(IMenuItem* item, Order& order) override;
};
