#pragma once
#include "../BaseCommand/BaseCommand.h"
#include <vector>

class AddCommand : public BaseCommand {
public:
	AddCommand() : BaseCommand("add","Adauga un produs. Ex: add capucino x1 large"){}
	void Execute(const std::vector<std::string>& tokens, Order& order) override;
};