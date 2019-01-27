/*
    * File Name : AccountHandler.h
    * Version : 0.8
    * Update Date : 2019.01.27
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include <Account.h>
#include <AccountPtrArray.h>

class AccountHandler
{
private:
    // 기존의 Account* pAccounts[100] 대신 새로 정의한 배열 클래스 사용
	AccountPtrArray arr;
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
