#pragma once
#include "../BaseCommand/BaseCommand.h"

class CompleteCommand : public BaseCommand {
public:
    CompleteCommand() : BaseCommand("complete", "Finalizeaza comanda") {} // Apelare Constructor in derivata
    void Execute(IMenuItem* item, Order& order) override;
};