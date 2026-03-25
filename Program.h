#pragma once
#include "Enums/UserTypes/UserTypes.h"
#include <string>
class Program
{
private:
	UserTypes StringToEnum(std::string input);

public:
	void Start();
};

