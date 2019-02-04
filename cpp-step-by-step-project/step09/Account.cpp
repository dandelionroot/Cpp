/*
    * File Name : Account.cpp
    * Version : 0.9
    * Update Date : 2019. 01. 29.
*/

#include <BankingCommonDecl.h>
#include <Account.h>

// name 멤버변수의 멤버 이니셜라이저에 의한 초기화 가능 (String 복사 생성자가 생성됨)
Account::Account(const int address, const String name, const double balance)
	:address(address), name(name), balance(balance) {}

const bool Account::addBalance(const double balance)
{
	this->balance += balance;
	return true;
}

const int Account::getAddress() const
{
	return this->address;
}

const String Account::getName() const
{
	return this->name;
}

void Account::showInfo() const
{
	cout << "계좌주소 : " << this->address << endl;
	cout << "고객이름 : " << this->name << endl;
	cout << "계좌잔액 : " << this->balance << endl;
}
