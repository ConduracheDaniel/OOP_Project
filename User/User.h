#pragma once
#include <string>
#include "../Enums/UserTypes/UserTypes.h"

class User
{
    std::string name;
	UserTypes type;
public:
	User(std::string name, UserTypes type) : name(name), type(type) {}
	std::string GetName() { return name; }
	UserTypes GetType() const{ return type; }
};

