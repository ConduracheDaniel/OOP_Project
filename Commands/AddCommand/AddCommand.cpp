#include "AddCommand.h"
#include "../../Order/Order.h"
using namespace std;
void AddCommand::Execute(IMenuItem* item, Order& order) {
	if (!item) {
		cout << "Format comanda invalid. Ex: add capucino x1 large \n";
		return;
	}
	order.AddItem(item);
	cout << "Adaugat: ";
	item->Display();
}