#include "ListCommand.h"
#include "../../Order/Order.h"
using namespace std;

void ListCommand::Execute(IMenuItem* item, Order& order) {
    const vector<IMenuItem*>& items = order.GetItems();
    if (items.empty()) {
        cout << "Comanda este goala.\n";
        return;
    }
    cout << "\n=== Produse in comanda ===\n";
    for (IMenuItem* i : items) {
        i->Display();
    }
    cout << "==========================\n";
}