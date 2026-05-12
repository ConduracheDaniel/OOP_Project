#include "CompleteCommand.h"
#include "../../Order/Order.h"
using namespace std;

void CompleteCommand::Execute(const vector<string>& tokens, Order& order) {
    if (order.GetItems().empty()) {
        cout << "Nu poti finaliza o comanda goala!\n";
        return;
    }
    order.Display();
    order.SetCompleted();

    cout << "Comanda a fost finalizata!\n";
    cout << "================================\n";
    cout << "  O comanda noua a inceput!\n";
    cout << "================================\n";
}