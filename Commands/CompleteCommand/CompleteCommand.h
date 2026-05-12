#pragma once
#include "../BaseCommand/BaseCommand.h"

class CompleteCommand : public BaseCommand {
public:
    CompleteCommand() : BaseCommand("complete", "Finalizeaza comanda") {} // Apelare Constructor in derivata
    void Execute(const std::vector<std::string>& tokens, Order& order) override;
};