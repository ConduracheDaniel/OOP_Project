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

    static int noOfItems;
  
public:
    // Constructor de initializare
    Item(std::string name, std::string description, int price, int quantity, std::string size)
        : name(name), description(description), price(price),
        quantity(quantity), size(size){
        noOfItems++;
    }

    // Constructor de copiere
    Item(const Item& other);

    // Operator= de copiere
    Item& operator=(const Item& other);

    virtual ~Item() {};

    // Getters
    std::string GetName() const override { return name; }
    std::string GetDescription() const override { return description; }
    int GetPrice() const override { return price; }
    int GetQuantity() const override { return quantity; }
    std::string GetSize() const override { return size; }
    void Display() const override;

    // operator+ ca functie membra (combina cantitati)
    Item operator+(const Item& other) const;

    // operator<< si operator>> ca functii non-membre
    friend std::ostream& operator<<(std::ostream& os, const Item& item);
    friend std::istream& operator>>(std::istream& is, Item& item);

    // operator== ca functie non-membra
    friend bool operator==(const Item& a, const Item& b);
};
