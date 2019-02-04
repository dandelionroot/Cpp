#include <iostream>
#include <bank-account-system6.h>
using std::cin;
using std::cout;
using std::endl;

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
