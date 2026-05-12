#pragma once
#include <vector>
#include "../Item/Item.h"
#include "../History/History.h"

using namespace std;
#include <iostream>
class Order
{
private:
    bool isCompleted = false;
	vector<IMenuItem*> items;
    vector<ICommand*> commands;
    History<vector<IMenuItem*>> commandHistory;


public:
    IMenuItem* CreateItem(const string& name, int qty, const string& size);
    Order();
    void ProcessCommand(const string& input);
    void Display() const;
    bool IsCompleted() const { return isCompleted; }
    void SetCompleted() { isCompleted = true; }

    void AddItem(IMenuItem* item) { items.push_back(item); }
    void RemoveItem(const string& name);
    History<vector<IMenuItem*>>& GetCommandHistory(){ return commandHistory; } // pentru modificari
    const History<vector<IMenuItem*>>& GetCommandHistory() const { return commandHistory; } // pentru Display
    const vector<IMenuItem*>& GetItems() const { return items; }

    IMenuItem* FindItemInOrder(const string& name);

    IMenuItem* FindItemInOrder(const string& name, const string& size);

    void Reset();

    ~Order();
};

