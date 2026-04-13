#include "Program.h"
#include <iostream>
#include "String functions/Strings.cpp"

using namespace std;

void Program::Start(Order order)
{
	cout << "Ai pornit programul\n";

	while (!order.IsCompleted()) {
		string input;
		cout << "Introdu comanda (sau 'help' pentru ajutor): ";
		getline(cin, input);
		order.ProcessCommand(toLower(input)); 
	}
	order.Display();
}
