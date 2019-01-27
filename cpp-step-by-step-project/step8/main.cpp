/*
    * File Name : main.cpp
    * Version : 0.7
    * Update Date : 2019.01.21
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void)
{
	AccountHandler handler;
	int select;
	while(true) {
		handler.showMenu();
		cout << "선택 : ";
		cin >> select;

		switch(select) {
		case MAKE :
			handler.makeAccount();
			break;
		case DEPOSIT :
			handler.deposit();
			break;
		case WITHDRAW :
			handler.withdrawal();
			break;
		case PRINT :
			handler.allPrint();
			break;
		case EXIT :
			return 0;
		default :
			cout << "잘못된 메뉴 번호입니다." << endl;
			break;
		}
	}
	return 0;
}
