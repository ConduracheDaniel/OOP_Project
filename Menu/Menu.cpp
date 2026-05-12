#include "Menu.h"

Menu* Menu::instance = nullptr;

Menu::Menu() {
    availableItems.insert(Americano::ClassName);
    availableItems.insert(Capucino::ClassName);
    availableItems.insert(Espresso::ClassName);
    availableItems.insert(Latte::ClassName);
    availableItems.insert(OrangeJuice::ClassName);
    availableItems.insert(SparklingWater::ClassName);
}

Menu* Menu::GetInstance()
{
    if (!instance)
        instance = new Menu();
    return instance;
}

bool Menu::Contains(const string& name) const
{
    return availableItems.find(name) != availableItems.end();
}

void Menu::Display()const {
    cout << "\n=== Meniu disponibil ===\n";
    for (const string& item : availableItems) {
        cout << "  - " << item << "\n";
    }
    cout << "========================\n";
}
