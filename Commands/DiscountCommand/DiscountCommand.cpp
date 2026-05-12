#include "../DiscountCommand/DiscountCommand.h"
#include "../../Item/Coffee/Americano/Americano.h"
#include "../../Order/Order.h"

void DiscountCommand::Execute(const vector<string>& tokens, Order& order)
{
    if (tokens.size() < 2) {
        cout << "Format invalid. Ex: discount capucino\n";
        return;
    }

    string name = tokens[1];

    IMenuItem* item = order.FindItemInOrder(name);

    if (!item) {
        cout << "Produsul '" << name << "' nu a fost gasit in comanda.\n";
        return;
    }

    Americano* americano = dynamic_cast<Americano*>(item); // downcast
    if (americano) {
        cout << "Ai aplicat discount de 5% la un produs americano\n";
        americano->SetPrice(americano->GetPrice() * 0.95); 
        return;
    }

    cout << "Produs fara discount.\n";
}
