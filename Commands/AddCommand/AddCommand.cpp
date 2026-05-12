#include "AddCommand.h"
#include "../../Order/Order.h"
#include "../../Exceptions/ItemNameException/ItemNameException.h"
#include "../../Exceptions/SizeExeption/SizeException.h"
using namespace std;

void AddCommand::Execute(const vector<string>& tokens, Order& order)
{
    if (tokens.size() < 4) {
        cout << "Format invalid. Ex: add capucino x1 large\n";
        return;
    }
    string name = tokens[1];
    int qty = stoi(tokens[2].substr(1));
    string size = tokens[3];

    try {
        IMenuItem* item = order.CreateItem(name, qty, size);
        order.AddItem(item);
        cout << "Adaugat: ";
        item->Display();
    }
    catch (const ItemNameException& e) { cout << e.what() << "\n"; }
    catch (const SizeException& e) { cout << e.what() << "\n"; }
}
