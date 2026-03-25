#include "Item.h"
#include "../Interfaces/ICommand/ICommand.h"
#include <iostream>
#include <string>


void Item::Display()
{
	std::cout << "\n" << GetName();
	std::cout << "\n" << GetDescription();
}


void Item::ProcessCommand(std::string input, User user)
{
	if (commands.find(input) != commands.end())
		commands[input]->Execute(user, *this);
	else
		HandleCustomCommand(input, user);
}

string Item::GetContextualHelp() {
	string basicCommands = "";
	for (auto const& comand : commands) {
		if (!basicCommands.empty())
			basicCommands += ", ";

		basicCommands += comand.first;
	}
	return basicCommands;
}
