#pragma once
#include "../BaseCommand/BaseCommand.h"

class DiscountCommand : public BaseCommand {
public:
    DiscountCommand() : BaseCommand("discount", "Pune un discount la un produs") {}
    void Execute(IMenuItem* item, Order& order) override;
};
