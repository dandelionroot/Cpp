/*
    * File Name : Account.cpp
    * Version : 0.7
    * Update Date : 2019. 01. 21.
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
private:
	int address;
	char *name;
	double balance;
public:
	Account(const int address, const char *name,
        const double balance);
	Account(const Account &copy);
	virtual const bool addBalance(const double balance);
	const int getAddress() const;
	const char* getName() const;
	virtual void showInfo() const;
	~Account();
};

#endif
