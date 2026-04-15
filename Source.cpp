#include "Program.h"
#include "Item/Coffee/Coffee.h"
int main() {
	Program program;
	Order order;
	program.Start(order);

	// exeplu UPcas
	// Metoda Display() din clasa Coffee (derivata din Item) supraincarca methoda virtuala Display() din clasa Item
	/*
	Coffee* espresso = new Coffee("Espresso", "Cafea neagra concentrata",
		10, 1, "small", "dark", false);

	Item* item = espresso; // UPcast
	item->Display(); 
	*/
	return 0;
}