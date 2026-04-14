#include "../BaseCommand/BaseCommand.h"

class RemoveCommand : public BaseCommand {
public:
    RemoveCommand() : BaseCommand("remove", "Elimina un produs. Ex: remove capucino") {}
    void Execute(IMenuItem* item, Order& order) override;
};