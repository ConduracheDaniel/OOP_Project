#include "RemoveCommand.h"
#include "../../Order/Order.h"
using namespace std;

void RemoveCommand::Execute(IMenuItem* item, Order& order) {
    if (!item) {
        cout << "Format invalid. Exemplu: remove capucino\n";
        return;
    }
    order.RemoveItem(item->GetName());
}