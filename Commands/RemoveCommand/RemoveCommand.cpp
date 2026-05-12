#include "RemoveCommand.h"
#include "../../Order/Order.h"
using namespace std;
void RemoveCommand::Execute(const vector<string>& tokens, Order& order)
{
    if (tokens.size() < 2) {
        cout << "Format invalid. Ex: remove capucino\n";
        return;
    }
    order.RemoveItem(tokens[1]);
}
