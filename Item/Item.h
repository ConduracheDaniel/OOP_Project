#pragma once
#include "../Interfaces/IMenuItem/IMenuItem.h"
#include "../Interfaces/ICommand/ICommand.h"
#include "../User/User.h"
#include <memory>
#include <unordered_map>
using namespace std;
class Item : public IMenuItem
{
    protected:
        unordered_map<string, shared_ptr<ICommand>> commands;
public:
    void Display() override;
    void ProcessCommand(std::string input, User user) override;
    virtual void HandleCustomCommand(string input, User user) = 0;
    virtual string GetContextualHelp() = 0;
};
