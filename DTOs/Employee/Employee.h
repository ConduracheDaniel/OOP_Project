#include <iostream>
#pragma once
#include <string>
using namespace std;
class Employee
{
	string name;
	int age;
	int salary;
	string ID; //unicitate cu static
public:
	// Constructor
	Employee(string name, int age, int salary, string ID);

	// Constructor copiere
	Employee(const Employee& other) {
		name = other.name;
		age = other.age;
		salary = other.salary;
		ID = other.ID;
	}

	// Destructor
	~Employee() {}

	// Getters
	string getName();
	int getAge();
	int getSalary();
	string getID();

	// Setters
	void setAge(int age);
	void setSalary(int salary);

	// I/O operators
	friend ostream& operator<<(ostream& os, const Employee& employee) {
		os << "Name: " << employee.name <<"\n";
		os << "Age: " << employee.age <<"\n";
		os << "Salary: " << employee.salary <<"\n";
		os << "ID: " << employee.ID << "\n";
		return os;
	}
	friend istream& operator>>(istream& is, Employee& employee) {
		cout << "Enter name: ";
		getline(is, employee.name);
		cout << "Enter age: ";
		is >> employee.age;
		cout << "Enter salary: ";
		is >> employee.salary;
		is.ignore(); // ignora delimitatorul de sir dupa citirea salariului
		cout << "Enter ID: ";
		getline(is, employee.ID);
		return is;
	}
};

