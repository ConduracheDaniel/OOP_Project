#pragma once
#include <exception>
#include <string>

class HistoryException : public std::exception {
private:
	std::string message;
public:
	HistoryException() { message = "Istoricul este gol!\n"; }
	const char* what() const noexcept override { return message.c_str();}
};