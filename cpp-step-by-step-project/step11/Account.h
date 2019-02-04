/*
    * File Name : Account.h
    * Version : 1.0
    * Update Date : 2019. 02. 04.
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <String.h>

class Account
{
private:
	int address;
	String name;
	double balance;
public:
	Account(const int address, const String name,
        const double balance);
	// 깊은 복사를 위한 복사 생성자와 대입 연산자가 필요 없어짐
	// 디폴트 복사 생성자와 디폴트 대입 연산자가 멤버 대 멤버의
	// 복사를 수행할 때 String 클래스의 깊은 복사를 수행하는 
	// 복사 생성자 또는 대입 연산자가 호출되므로
	// Account(const Account& copy);
        // Account& operator= (const Account& copy);
	virtual const bool addBalance(const double balance);
	const int getAddress() const;
	const String getName() const;
	const double getBalance() const;
	virtual void showInfo() const;
	~Account();
};

#endif
