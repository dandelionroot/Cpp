#include <iostream>
#include <cstring>
#include <bank-account-system2.h>
using namespace std;

Account* pAccount[100];
int accum = 0;

void showMenu()
{
	cout << "\n";
	cout << "**MENU**" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

Account::Account(int address, char *name, double balance)
	:address(address), balance(balance)
{
	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy(this->name, name);
}

bool Account::AddBalance(double balance)
{
	this->balance += balance;
	return true;
}

const int Account::GetAddress() const
{
	return this->address;
}

const char *Account::GetName() const
{
	return this->name;
}

void Account::ShowInfo() const
{
	cout << "계좌주소 : " << this->address << endl;
	cout << "고객이름 : " << this->name << endl;
	cout << "계좌잔액 : " << this->balance << endl;
}

Account::~Account()
{
	delete []name;
}

Account *makeAccount()
{
	int address;
	char name[15];
	double balance;

	cout << "계좌주소 : ";
	cin >> address;
	cout << "성함 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> balance;

	Account* pReturn = new Account(address, name, balance);
	pAccount[accum] = pReturn;
	accum++;
	return pReturn;
}

void deposit()
{
	int address;
	double balance;

	cout << "입금계좌주소 : ";
	cin >> address;

	int i;
	for(i = 0; i < accum; i++) {
		if(pAccount[i]->GetAddress() == address)
			break;
	}

	if(i == accum) {
		cout << "찾으시는 계좌가 없습니다. 다시 시도해 주세요." << endl;
		return;
	}

	cout << "입금금액 : ";
	cin >> balance;

	if(pAccount[i]->AddBalance(balance))
		cout << pAccount[i]->GetName() << " 에게 " 
		<< balance << " 원 입금 완료 !" << endl;
}

void withdrawal()
{
	int address;
	double balance;

	cout << "출금계좌주소 : ";
	cin >> address;

	int i;
	for(i = 0; i < accum; i++) {
		if(pAccount[i]->GetAddress() == address)
			break;
	}

	if(i == accum) {
		cout << "찾으시는 계좌가 없습니다. 다시 시도해 주세요." << endl;
		return;
	}

	cout << "출금금액 : ";
	cin >> balance;

	if(pAccount[i]->AddBalance(-balance))
		cout << pAccount[i]->GetName() << " 계좌에서 " 
		<< balance << " 원 출금 완료 !" << endl;
}

void allPrint() {
	cout << "**전체 계좌정보 출력**" << endl;
	for(int i=0; i<accum; i++) {
		cout << "-" << i+1 << "번째 고객정보" << endl;
		pAccount[i]->ShowInfo();
	}
}
