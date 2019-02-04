/*
    * File Name : AccountHandler.h
    * Version : 1.0
    * Update Date : 2019. 01. 30.
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include <Account.h>
#include <BoundCheckPtrArray.h>

typedef Account* ACCOUNT_PTR;

class AccountHandler
{
private:
	BoundCheckPtrArray<Account> arr;
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
