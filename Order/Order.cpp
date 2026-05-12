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
#include "../Commands/MenuCommand/MenuCommand.h"
#include "../Commands/HistoryCommand/HistoryCommand.h"

#include "../Item/Coffee/Capucino/Capucino.h"
#include "../Item/Coffee/Esptesso/Espresso.h"
#include "../Item/Coffee/Latte/Latte.h"
#include "../Item/Coffee/Americano/Americano.h"
#include "../Item/Drinks/Water/SparklingWater.h"
#include "../Item/Drinks/OrangeJuice/OrangeJuice.h"
#include "../Enums/SizeEnum/ParseSize.cpp"

#include "../Menu/Menu.h"


IMenuItem* Order::CreateItem(const string& name, int qty, const string& inputSize) {

	if (!Menu::GetInstance()->Contains(name)) {
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

	if (name == Capucino::ClassName)		return new Capucino(qty, size);
	if (name == Espresso::ClassName)		return new Espresso(qty, size);
	if (name == Latte::ClassName)			return new Latte(qty, size);
	if (name == Americano::ClassName)		return new Americano(qty, size);
	if (name == SparklingWater::ClassName)	return new SparklingWater(qty, size);
	if (name == OrangeJuice::ClassName)		return new OrangeJuice(qty, size);
	return nullptr;
}


Order::Order() {
	commands.push_back(new AddCommand());
	commands.push_back(new RemoveCommand());
	commands.push_back(new ListCommand());
	commands.push_back(new MenuCommand());
	commands.push_back(new HistoryCommand());
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


	matched->Execute(tokens, *this);
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

void Order::Reset()
{
	commandHistory.Push(items);
	items.clear();
	isCompleted = false;
}

Order::~Order()
{
	for (IMenuItem* item : items) delete item;
	for (ICommand* cmd : commands) delete cmd;
}