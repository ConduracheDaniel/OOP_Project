#pragma once
#include <vector>
#include "../Item/Item.h"
using namespace std;
#include <iostream>
class Order
{
private:
    bool isCompleted = false;
	vector<IMenuItem*> items;
    vector<ICommand*> commands;

public:
    void RegisterCommand(ICommand* cmd);
    void ProcessCommand(const string& input);
    void Display() const;
    bool IsCompleted() const { return isCompleted; }
    void SetCompleted() { isCompleted = true; }

    void AddItem(IMenuItem* item) { items.push_back(item); }
    void RemoveItem(const string& name);
    const vector<IMenuItem*>& GetItems() const { return items; }
};

