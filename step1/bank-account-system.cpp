#include <bank-account-system.h>
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

int currentCount = 0;
Account accounts[ACCOUNT_NUMBER];

void showMenu() {
	cout << "\n";
	cout << "**MENU**" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void makeAccount() {
	int id;
	char name[NAME_LENGTH];
	double value;

	cout << "계좌ID : ";
	cin >> id;
	cout << "성함 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> value;

	accounts[currentCount].id = id;
	strcpy(accounts[currentCount].name, name);
	accounts[currentCount].value = value;

	currentCount++;
	cout << id << " 계좌정보 등록 완료 !" << endl;
}

void deposit() {
	int i = 0;
	int id;
	double value;

	cout << "입금계좌ID : ";
	cin >> id;

	while(accounts[i].id != id)
		i++;

	cout << "입금금액 : ";
	cin >> value;

	accounts[i].value += value;

	cout << accounts[i].name << " 에게 " << value << " 원 입금 완료 !" << endl;
}

void withdrawal() {
	int i = 0;
	int id;
	double value;

	cout << "출금계좌ID : ";
	cin >> id;

	while(accounts[i].id != id)
		i++;

	cout << "출금금액 : ";
	cin >> value;

	accounts[i].value -= value;

	cout << accounts[i].name << " 계좌에서 " << value << " 원 출금 완료 !" << endl;
}

void allPrint() {
	cout << "**전체 계좌정보 출력**" << endl;
	for(int i=0; i<currentCount; i++) {
		cout << "-" << i+1 << "번째 고객정보" << endl;
		cout << "고객ID : " << accounts[i].id << endl;
		cout << "고객이름 : " << accounts[i].name << endl;
		cout << "계좌잔액 : " << accounts[i].value << endl;
	}
}
