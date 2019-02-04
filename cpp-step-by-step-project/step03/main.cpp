#include <iostream>
#include <bank-account-system3.h>
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	int select;
	while(1) {
		showMenu();
		cout << "선택 : ";
		cin >> select;

		switch(select) {
		case MAKE :
			makeAccount();
			break;
		case DEPOSIT :
			deposit();
			break;
		case WITHDRAW :
			withdrawal();
			break;
		case PRINT :
			allPrint();
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
