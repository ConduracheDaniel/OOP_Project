#pragma once
#include <vector>
#include "../Item/Item.h"
#include <set>
#include <map>
using namespace std;
#include <iostream>
class Order
{
private:
    bool isCompleted = false;
	vector<IMenuItem*> items;
    vector<ICommand*> commands;
    set<string>availableItems;
    IMenuItem* CreateItem(const string& name, int qty, const string& size);

    void RegisterItems();
public:
    Order();
    void ProcessCommand(const string& input);
    void Display() const;
    const set<string>& GetAvailableItems() const { return availableItems; }
    bool IsCompleted() const { return isCompleted; }
    void SetCompleted() { isCompleted = true; }

    void AddItem(IMenuItem* item) { items.push_back(item); }
    void RemoveItem(const string& name);
    const vector<IMenuItem*>& GetItems() const { return items; }

    IMenuItem* FindItemInOrder(const string& name);

    IMenuItem* FindItemInOrder(const string& name, const string& size);

    ~Order();
};

