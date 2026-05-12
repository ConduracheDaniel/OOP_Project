#include "HistoryCommand.h"
#include "../../Order/Order.h"

void HistoryCommand::Execute(const vector<string>& tokens, Order& order)
{
	order.GetCommandHistory().Display();
}
