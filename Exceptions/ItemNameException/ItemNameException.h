#pragma once
#include <exception>
#include <string>

class ItemNameException : public std::exception {
private:
	std::string message;
public:
	ItemNameException(const std::string& itemName) {
		message = "Produsul nu e in meniu: " + itemName + "\n";
	}
	const char* what() const noexcept override {
		return message.c_str();
	}
};