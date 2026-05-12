#pragma once
#include "../BaseCommand/BaseCommand.h"
#include <vector>
class MenuCommand : public BaseCommand {
public:
    MenuCommand() : BaseCommand("menu", "Afiseaza produsele disponibile") {}
    void Execute(const std::vector<std::string>& tokens, Order& order) override;
};