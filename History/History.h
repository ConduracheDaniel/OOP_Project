#pragma once
#include <stack>
#include <vector>
#include "../Exceptions/HistoryException/HistoryException.h"
#include <iostream>
using namespace std;
template <typename T> class History {
private:
	stack<T> history;
public:
	void Push(const T& item) {
		history.push(item);
	}

	T Pop() {
		if (history.empty())
			throw HistoryException();
		T top = history.top();
		history.pop();
		return top;
	}

	T Peak() const{
		if (history.empty())
			throw HistoryException();
		return history.top();
	}

	void Display()const {
		if (history.empty()) {
			std::cout << "Nu exista comenzi finalizate.\n";
			return;
		}

		std::stack<std::vector<IMenuItem*>> temp = history;
		std::vector<std::vector<IMenuItem*>> sessions;

		while (!temp.empty()) {
			sessions.push_back(temp.top());
			temp.pop();
		}

		std::cout << "\n=== Istoric comenzi ===\n";
		for (int i = static_cast<int>(sessions.size()) - 1; i >= 0; i--) {
			std::cout << "  Comanda " << (sessions.size() - i) << ":\n";
			for (IMenuItem* item : sessions[i]) {
				item->Display();
			}
		}
		std::cout << "=======================\n";
	}

};