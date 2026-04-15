#include "Order.h"
#include <sstream>

#include "../Commands/AddCommand/AddCommand.h"
#include "../Commands/RemoveCommand/RemoveCommand.h"
#include "../Commands/ListCommand/ListCommand.h"
#include "../Commands/HelpCommand/HelpCommand.h"
#include "../Commands/CompleteCommand/CompleteCommand.h"

#include "../Item/Coffee/Capucino/Capucino.h"
#include "../Item/Coffee/Esptesso/Espresso.h"
#include "../Item/Coffee/Latte/Latte.h"
#include "../Item/Coffee/Americano/Americano.h"
#include "../Item/Drinks/Water/SparklingWater.h"
#include "../Item/Drinks/OrangeJuice/OrangeJuice.h"

IMenuItem* Order::CreateItem(const string& name, int qty, const string& size) {
	if (name == "capucino")  return new Capucino(qty, size);
	if (name == "espresso")  return new Espresso(qty, size);
	if (name == "latte")     return new Latte(qty, size);
	if (name == "americano") return new Americano(qty, size);
	if (name == "sparklingwater") return new SparklingWater(qty, size);
	if (name == "orangejuice")return new OrangeJuice(qty, size);
	return nullptr;
}

Order::Order() {
	commands.push_back(new AddCommand());
	commands.push_back(new RemoveCommand());
	commands.push_back(new ListCommand());
	commands.push_back(new CompleteCommand());
	commands.push_back(new HelpCommand(commands));
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
			cout << "Produs necunoscut: " << itemName << "\n";
			return;
		}
	}
	matched->Execute(item, *this);
}

void Order::Display() const {
	if (items.empty()) {
		cout << "Lista comenzi este goala.\n";
		return;
	}

	cout << "\n === Comanda ta === \n";
	int total = 0;

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
		cout << "Produsul '" << name << "' nu a fost gasit in comanda.\n";
	}
}

Order::~Order()
{
	for (IMenuItem* item : items) delete item;
	for (ICommand* cmd : commands) delete cmd;
}