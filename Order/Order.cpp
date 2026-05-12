#include "Order.h"
#include <sstream>
#include "../StringFunctions/Strings.h"

#include "../Enums/SizeEnum/SizeEnum.h"
#include "../Exceptions/SizeExeption/SizeException.h"
#include "../Exceptions/ItemNameException/ItemNameException.h"

#include "../Commands/AddCommand/AddCommand.h"
#include "../Commands/RemoveCommand/RemoveCommand.h"
#include "../Commands/ListCommand/ListCommand.h"
#include "../Commands/HelpCommand/HelpCommand.h"
#include "../Commands/CompleteCommand/CompleteCommand.h"
#include "../Commands/DiscountCommand/DiscountCommand.h"

#include "../Item/Coffee/Capucino/Capucino.h"
#include "../Item/Coffee/Esptesso/Espresso.h"
#include "../Item/Coffee/Latte/Latte.h"
#include "../Item/Coffee/Americano/Americano.h"
#include "../Item/Drinks/Water/SparklingWater.h"
#include "../Item/Drinks/OrangeJuice/OrangeJuice.h"
#include "../Enums/SizeEnum/ParseSize.cpp"

IMenuItem* Order::CreateItem(const string& name, int qty, const string& inputSize) {

	if (availableItems.find(name) == availableItems.end()) {
		throw ItemNameException(name);
	}

	Size size;
	try {
		size = ParseSize(inputSize);
	}
	catch (const SizeException& e) {
		cout << e.what() << "\n";
		return nullptr;
	}
	catch (const std::invalid_argument& e) {
		cout << "Argument invalid: " << e.what() << "\n";
		return nullptr;
	}
	catch (const std::exception& e) {
		cout << "Eroare: " << e.what() << "\n";
		return nullptr;
	}

	if (name == Capucino::ClassName)			return new Capucino(qty, size);
	if (name == Espresso::ClassName)			return new Espresso(qty, size);
	if (name == Latte::ClassName)			return new Latte(qty, size);
	if (name == Americano::ClassName)		return new Americano(qty, size);
	if (name == SparklingWater::ClassName)	return new SparklingWater(qty, size);
	if (name == OrangeJuice::ClassName)		return new OrangeJuice(qty, size);
	return nullptr;
}

void Order::RegisterItems()
{
	availableItems.insert(Capucino::ClassName);
	availableItems.insert(Espresso::ClassName);
	availableItems.insert(Latte::ClassName);
	availableItems.insert(Americano::ClassName);
	availableItems.insert(SparklingWater::ClassName);
	availableItems.insert(OrangeJuice::ClassName);
}

Order::Order() {
	commands.push_back(new AddCommand());
	commands.push_back(new RemoveCommand());
	commands.push_back(new ListCommand());
	commands.push_back(new CompleteCommand());
	commands.push_back(new HelpCommand(commands));
	commands.push_back(new DiscountCommand());
	
}

void Order::ProcessCommand(const string& input) {

	vector<string> tokens;
	stringstream ss(input);
	string token;

	while (ss >> token)
		tokens.push_back(token);

	if (tokens.empty()) return;

	string commandName = tokens[0];

	ICommand* matched = nullptr;
	for (ICommand* cmd : commands) {
		if (cmd->GetName() == commandName) {
			matched = cmd;
			break;
		}
	}

	if (!matched) {
		cout << "Comanda necunoscuta: " << commandName << "\n";
		return;
	}

	IMenuItem* item = nullptr;

	if (tokens.size() >= 4) {
		string itemName = tokens[1];
		int qty = stoi(tokens[2].substr(1));
		string size = tokens[3];

		item = CreateItem(itemName, qty, size);

		if (!item) {
			return; 
		}
	}
	else if (tokens.size() >= 3) {
		item = FindItemInOrder(tokens[1], tokens[2]); // pentru verificarea in lista a produsului bazat doar pe nume
	}
	else if (tokens.size() == 2) {
		item = FindItemInOrder(tokens[1]); // pentru verivicarea produsului in lista bazat pe nume si marime
	}

	matched->Execute(item, *this);
}

void Order::Display() const {
	if (items.empty()) {
		cout << "Lista comenzi este goala.\n";
		return;
	}

	cout << "\n === Comanda ta === \n";
	double total = 0;

	for (IMenuItem* item : items) {
		item->Display();
		total += item->GetPrice() * item->GetQuantity();
	}
	cout << "========================\n";
	cout << "Total: " << total << " Lei\n";
}

void Order::RemoveItem(const string& name) {
	for (auto it = items.begin(); it != items.end(); ++it) {
		if ((*it)->GetName() == name) {
			delete* it;
			items.erase(it);
			cout << "Ai eliminat '" << name << "' din comanda\n";
			return;
		}
		
	}
	cout << "Produsul '" << name << "' nu a fost gasit in comanda.\n";
}

IMenuItem* Order::FindItemInOrder(const string& name)
{
	for (auto& item : items) {
		if (toLower(item->GetName()) == toLower(name))
			return item;
	}
	return nullptr;
}

IMenuItem* Order::FindItemInOrder(const string& name, const string& size)
{
	for (auto& item : items) {
		if (toLower(item->GetName()) == toLower(name) && item->GetSize() == size)
			return item;
	}
	return nullptr;
}

Order::~Order()
{
	for (IMenuItem* item : items) delete item;
	for (ICommand* cmd : commands) delete cmd;
}