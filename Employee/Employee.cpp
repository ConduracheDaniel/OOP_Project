#include "Employee.h"

Employee::Employee(string name, int age, int salary, string ID)
{
	this->name = name;
	this->age = age;
	this->salary = salary;
	this->ID = ID;
}

string Employee::getName()
{
	return name;
}

int Employee::getAge()
{
	return age;
}

int Employee::getSalary()
{
	return salary;
}

string Employee::getID()
{
	return ID;
}

void Employee::setAge(int age)
{
	this->age = age;
}

void Employee::setSalary(int salary)
{
	this->salary = salary;
}


