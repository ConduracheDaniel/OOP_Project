#pragma once
#include <string>
#include "../PaymentBase.h"

class Card : public PaymentBase
{
	std::string cardNumber;
	std::string cardHolderName;

};

