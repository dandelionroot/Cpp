/*
    * File Name : Account.cpp
    * Version : 0.7
    * Update Date : 2019.01.21
*/

#include <BankingCommonDecl.h>
#include <Account.h>

Account::Account(const int address, const char *name, const double balance)
	:address(address), balance(balance)
{
	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy(this->name, name);
}

Account::Account(const Account &copy)
	:address(copy.address), balance(copy.balance)
{
	int len = strlen(copy.name) + 1;
	this->name = new char[len];
	strcpy(this->name, copy.name);
}

const bool Account::addBalance(const double balance)
{
	this->balance += balance;
	return true;
}

const int Account::getAddress() const
{
	return this->address;
}

const char* Account::getName() const
{
	return this->name;
}

void Account::showInfo() const
{
	cout << "계좌주소 : " << this->address << endl;
	cout << "고객이름 : " << this->name << endl;
	cout << "계좌잔액 : " << this->balance << endl;
}

Account::~Account()
{
	delete []name;
}
