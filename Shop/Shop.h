#pragma once
#include <string>
#include "../Employee/Employee.h"
#include "../Order/Order.h"
#include <vector>
using namespace std;
class Shop
{
	string address;
	vector<Employee> employees;
	vector<Order> orders;
public:
	Shop(string address);
	string getAddress();
};

