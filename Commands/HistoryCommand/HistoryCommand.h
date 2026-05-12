#pragma once
#include "../BaseCommand/BaseCommand.h"
class HistoryCommand : public BaseCommand {
public:
	HistoryCommand() : BaseCommand("history", "Afiseaza istoricul de comenzi") {}
	void Execute(const std::vector<std::string>& tokens, Order& order) override;
};