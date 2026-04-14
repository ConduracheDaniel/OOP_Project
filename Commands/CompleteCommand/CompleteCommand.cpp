#include "CompleteCommand.h"
#include "../../Order/Order.h"
using namespace std;

void CompleteCommand::Execute(IMenuItem* item, Order& order) {
    if (order.GetItems().empty()) {
        cout << "Nu poti finaliza o comanda goala!\n";
        return;
    }
    order.SetCompleted();
    cout << "Comanda a fost finalizata!\n";
}