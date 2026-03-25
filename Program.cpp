#include "Program.h"
#include <iostream>
#include "String functions/Strings.cpp"
using namespace std;

UserTypes Program::StringToEnum(string input)
{
	input = toLower(input);
	if (input == "admin") return UserTypes::ADMIN;
	if (input == "user") return UserTypes::USER;
	return UserTypes::NONE;
}
void Program::Run()
{
	string input;
	cout << "Ai pornit aplicatia!\n";
	cout << "Introdu tipul utilizatorului: \n1. Admin\n2. User\n";
	cin >> input;

}
