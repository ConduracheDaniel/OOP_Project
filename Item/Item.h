#pragma once
#include "../Interfaces/IMenuItem/IMenuItem.h"
#include "../Interfaces/ICommand/ICommand.h"
#include "../Enums/SizeEnum/SizeEnum.h"
using namespace std;
class Item : public IMenuItem
{
private:
    std::string name;
    std::string description;
    double price;
    int quantity;
    Size size;

  
public:
    // Constructor de initializare
    Item(std::string name, std::string description, double price, int quantity, Size size)
        : name(name), description(description), price(price),
        quantity(quantity), size(size){
    }

    // Constructor de copiere
    Item(const Item& other);

    // Operator= de copiere
    Item& operator=(const Item& other);

    virtual ~Item() {};

    // Getters
    std::string GetName() const override { return name; }
    std::string GetDescription() const override { return description; }
    double GetPrice() const override { return price; }
    int GetQuantity() const override { return quantity; }
    std::string GetSize() const override { 
        switch (size) {
            case Size::SMALL: return "small";
            case Size::MEDIUM: return "medium";
            case Size::LARGE: return "large";
            default: return "unknown";
        }
    
    }
    void Display() const override;

    // operator+ ca functie membra (combina cantitati)
    Item operator+(const Item& other) const;

    // operator<< si operator>> ca functii non-membre
    friend std::ostream& operator<<(std::ostream& os, const Item& item);
    friend std::istream& operator>>(std::istream& is, Item& item);

    // operator== ca functie non-membra
    friend bool operator==(const Item& a, const Item& b);

    void SetPrice(int newPrice);
};
