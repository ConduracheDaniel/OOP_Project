#pragma once
#include "../BaseCommand/BaseCommand.h"

class CompleteCommand : public BaseCommand {
public:
    CompleteCommand() : BaseCommand("complete", "Finalizeaza comanda") {}
    void Execute(IMenuItem* item, Order& order) override;
};