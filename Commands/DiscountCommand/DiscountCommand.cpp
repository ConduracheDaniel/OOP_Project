#include "../DiscountCommand/DiscountCommand.h"
#include "../../Item/Coffee/Americano/Americano.h"

void DiscountCommand::Execute(IMenuItem* item, Order& order)
{
	Americano* americano = dynamic_cast<Americano*>(item); //Down cast

	if (americano) {
		cout << "Ai aplicat discount de 5% la un produs americano\n";
		americano->SetPrice(americano->GetPrice() - (americano->GetPrice()*0.05));
		return;
	}

	cout << "produs fara discount\n";
}
