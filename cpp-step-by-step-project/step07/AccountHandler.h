/*
    * File Name : AccountHandler.h
    * Version : 0.7
    * Update Date : 2019.01.21
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include <Account.h>

class AccountHandler
{
private:
	Account* pAccounts[100];
	int num;
public:
	AccountHandler();
	void makeAccount();
	void deposit() const;
	void withdrawal() const;
	void allPrint() const;
	static void showMenu();
};

#endif
