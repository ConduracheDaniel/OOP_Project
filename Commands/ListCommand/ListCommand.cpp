#include "ListCommand.h"
#include "../../Order/Order.h"
using namespace std;

void ListCommand::Execute(const vector<string>& tokens, Order& order)
{ 
	order.Display();
}
