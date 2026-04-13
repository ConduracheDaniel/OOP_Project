#pragma once
#include "../Interfaces/IMenuItem/IMenuItem.h"
#include "../Interfaces/ICommand/ICommand.h"
using namespace std;
class Item : public IMenuItem
{
private:
    std::string name;
    std::string description;
    int price;
    int quantity;
    std::string size;
    std::string itemID;
  
public:
    Item(std::string name, std::string description, int price, int quantity, std::string size, std::string itemID)
        : name(name), description(description), price(price),
        quantity(quantity), size(size), itemID(itemID) {
    }

    std::string GetName() const override { return name; }
    std::string GetDescription() const override { return description; }
    int GetPrice() const override { return price; }
    std::string GetItemID() const override { return itemID; }
    int GetQuantity() const override { return quantity; }
    std::string GetSize() const override { return size; }
    void Display() const override;
};
