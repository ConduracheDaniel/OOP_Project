#include "Program.h"
#include <iostream>
#include "String functions/Strings.cpp"
#include "User/User.h"
using namespace std;

UserTypes Program::StringToEnum(string input)
{
	input = toLower(input);
	if (input == "admin") return UserTypes::ADMIN;
	if (input == "user") return UserTypes::USER;
	return UserTypes::NONE;
}
void Program::Start()
{
	UserTypes type;
	string input;
	bool validInput = false;

	cout << "Ai pornit aplicatia!\n";

	while (!validInput) {
		cout << "\nIntrodu tipul utilizatorului: \n1. Admin\n2. User\n";
		cin >> input;
		type = StringToEnum(input);

		switch (type) {
		case UserTypes::ADMIN:
		case UserTypes::USER:
			validInput = true;
			break;
		default:
			cout << "\nOptiune utilizator invalida!\n";
			break;
		}
	}

	User user("@@@", type);

}
