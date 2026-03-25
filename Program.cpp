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
	string input;
	cout << "Ai pornit aplicatia!\n";
	cout << "Introdu tipul utilizatorului: \n1. Admin\n2. User\n";
	cin >> input;
	UserTypes type = StringToEnum(input);
	User user("@@@", type);

}
