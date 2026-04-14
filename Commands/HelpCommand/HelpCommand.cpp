#include "HelpCommand.h"
#include <iostream>

void HelpCommand::Execute(IMenuItem* item, Order& order) {
    std::cout << "\n ==== Comenzi disponibile ====\n";
    for (ICommand* cmd : commands) {
        cout << "  " << cmd->GetName()
            << " - " << cmd->GetDescription() << "\n";
    }
    cout << "===========================\n";
}


