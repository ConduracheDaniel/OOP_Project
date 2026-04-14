#include "Item.h"
#include <iostream>

Item::Item(const Item & other) : name(other.name), description(other.description),
price(other.price), quantity(other.quantity), size(other.size) {}

// Operator= de copiere
Item& Item::operator=(const Item& other) {
    if (this != &other) {           
        name = other.name;
        description = other.description;
        price = other.price;
        quantity = other.quantity;
        size = other.size;
        cout << "Operator= copiere: " << name << "\n";
    }
    return *this;
}
void Item::Display() const {
    std::cout << name
        << " x" << quantity
        << " (" << size << ")"
        << " - " << price << " RON\n";
}

Item Item::operator+(const Item& other) const
{
    Item result = *this;            
    result.quantity += other.quantity;      
    return result;
}

std::ostream& operator<<(std::ostream& os, const Item& item)
{
    os << item.name
        << " | " << item.description
        << " | Pret: " << item.price << " Lei"
        << " | Cantitate: " << item.quantity
        << " | Marime: " << item.size;
    return os;
}

std::istream& operator>>(std::istream& is, Item& item)
{
    cout << "Nume: ";
    is >> item.name;
    cout << "Descriere: ";
    is >> item.description;
    cout << "Pret: ";
    is >> item.price;
    cout << "Cantitate: ";
    is >> item.quantity;
    cout << "Marime: ";
    is >> item.size;
    return is;
}

bool operator==(const Item& a, const Item& b)
{
    return a.name == b.name;
}
