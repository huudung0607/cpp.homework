
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <climits>
#include <iomanip>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
class Employee {
private:
	string firstName, lastName, socialSecurityNumber;
public:
	Employee(string firstname, string lastName, string socialSecurityNumber) {
		this->firstName = firstname;
		this->lastName = lastName;
		this->socialSecurityNumber = socialSecurityNumber;
	}
	void setFirstName(string firstName) {
		this->firstName = firstName;
	}
	string getFirstName() {
		return firstName;
	}
	void setLastName(string lastName) {
		this->lastName = lastName;
	}
	string getLastName() {
		return lastName;
	}
	void setSocialSN(string socialSecurityNumber) {
		this->socialSecurityNumber = socialSecurityNumber;
	}
	string getSocialSN() {
		return socialSecurityNumber;
	}
	virtual double earnings() const = 0;
	virtual void print() const {
		cout << firstName << " " << lastName << endl << "Social Security Number : "
			<< socialSecurityNumber;
	}
};

class SalariedEmployee : public Employee {
private:
	double weeklySalary;
public:
	SalariedEmployee(string firstName, string lastName,
		string socialSecurityNumber, double weeklySalary)
		: Employee(firstName, lastName, socialSecurityNumber) {
		this->weeklySalary = weeklySalary;
	}
	void setWeeklySalary(double weeklySalary) {
		if (weeklySalary >= 0){
			this->weeklySalary = weeklySalary;
		}
		else{
			cout << "Weekly salary must be >= 0/0 ";
		}
	}
	double getWeeklySalary() const {
		return weeklySalary;
	}
	virtual double earnings() const {
		return getWeeklySalary();
	}
	virtual void print() const {
		cout << "Salaried Employee : ";
		Employee::print();
		cout << endl;
		cout << "Weekly Salary : " << weeklySalary;
	}
};
class CommissionEmployee : public Employee {
private:
	double grossSales, commissionRate;
public:
	CommissionEmployee(string firstName, string lastName, string socialSecurityNumber,
		double grossSales, double commissionRate) : Employee(firstName, lastName, socialSecurityNumber) {
		this->grossSales = grossSales;
		this->commissionRate = commissionRate;
	}
	void setGrossSales(double grossSales) {
		if (grossSales >= 0.0) {
			this->grossSales = grossSales;
		}
		else cout << "Gross Sales must be >= 0.0";
	}
	double getGrossSales() {
		return grossSales;
	}
	void setCommissionRate(double commissionRate) {
		if (commissionRate > 0.0 && commissionRate < 1.0) {
			this->commissionRate = commissionRate;
		}
		else cout << "Commission Rate must be > 0.0 and < 1.0";
	}
	double getCommissionRate() {
		return commissionRate;
	}
	virtual double earnings() const {
		return grossSales * commissionRate;
	}
	virtual void print() const {
		cout << "Commission employee : ";
		Employee::print();
		cout << endl;
		cout << "Gross Sales : " << grossSales << "; Commission Rate : " << commissionRate;
	}
};

class BasePlusCommissionEmployee : public CommissionEmployee {
private:
	double baseSalary;
public:
	BasePlusCommissionEmployee(string firstName, string lastName, string
		socialSecurityNumber, double grossSales, double commissionRate, double baseSalary) 
		: CommissionEmployee(firstName,lastName,socialSecurityNumber,grossSales,commissionRate) {
		this->baseSalary = baseSalary;
	}
	void setBaseSalary(double baseSalary) {
		if (baseSalary >= 0.0) {
			this->baseSalary = baseSalary;
		}
		else cout << "Base Salary must be >= 0.0";
	}
	double getBaseSalary() {
		return baseSalary;
	}
	virtual double earnings() const {
		return baseSalary + CommissionEmployee::earnings();
	}
	virtual void print() const {
		cout << "Base Salary : ";
		CommissionEmployee::print();
		cout << "; Base Salary : " << baseSalary;
	}
};
void virtualViaPointer(const Employee* const baseClassPtr) {
	baseClassPtr->print();
	cout << endl;
	cout << "Earned $" << baseClassPtr->earnings() << endl << endl;
}
void virtualViaReference(const Employee& baseClassRef) {
	baseClassRef.print();
	cout << endl;
	cout << "Earned $" << baseClassRef.earnings() << endl << endl;
}
int main()
{
	cout << fixed << setprecision(2);
	SalariedEmployee salariedEmploy("John", "Smith", "111-11-1111", 800);
	CommissionEmployee commissionEmploy("Sue", "John", "333-33-3333", 10000, 0.06);
	BasePlusCommissionEmployee BPCEmploy("Bob", "Lewis", "444-44-4444", 5000, 0.04, 300);
	salariedEmploy.print();
	cout << endl;
	cout << "Earned $ " << salariedEmploy.earnings() << endl << endl;
	commissionEmploy.print();
	cout << endl;
	cout << "Earned $ " << commissionEmploy.earnings() << endl << endl;
	BPCEmploy.print();
	cout << endl;
	cout << "Earned $ " << BPCEmploy.earnings() << endl << endl;
	cout << "HEHE" << endl;
	vector<Employee*> employ(3);
	employ[0] = &salariedEmploy;
	employ[1] = &commissionEmploy;
	employ[2] = &BPCEmploy;
	for (auto x : employ) {
		virtualViaPointer(x);
	}
	cout << "HEEH" << endl;
	cout << endl;
	for (auto x : employ) {
		virtualViaReference(*x);
	}
}

