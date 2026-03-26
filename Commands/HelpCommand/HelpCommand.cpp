#include "HelpCommand.h"
void HelpCommand::Execute(User user, IMenuItem& item) {
    std::cout << "Comenzi disponibile: \n";
    std::cout << item.GetContextualHelp() << "\n";
}


