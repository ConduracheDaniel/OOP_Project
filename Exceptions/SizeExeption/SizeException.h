#pragma once
#include <exception>
#include <string>
class SizeException : public std::exception {
private:
	std::string message;
public:
	SizeException(const std::string& size) {
		message = "Dimensiune invalida: '" + size + "'\n Valori acceptate: small, medium, large";
	}
	const char* what() const noexcept override {
		return message.c_str();
	}
};