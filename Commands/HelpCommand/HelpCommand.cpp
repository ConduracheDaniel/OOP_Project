#include "HelpCommand.h"
void HelpCommand::Execute(IMenuItem& item) {
    std::cout << "Comenzi disponibile: \n";
    std::cout << item.GetContextualHelp() << "\n";
}


