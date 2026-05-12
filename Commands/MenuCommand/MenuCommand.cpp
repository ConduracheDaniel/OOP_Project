#include "MenuCommand.h"
#include "../../Menu/Menu.h"
using namespace std;

void MenuCommand::Execute(const vector<string>& tokens, Order& order) {
    Menu::GetInstance()->Display();
}