#pragma once
#include "../BaseCommand/BaseCommand.h"

class AddCommand : public BaseCommand {
public:
	AddCommand() : BaseCommand("add","Adauge un produs. Ex: add capucino x1 large"){}
	void Execute(IMenuItem* item, Order& order) override;
};