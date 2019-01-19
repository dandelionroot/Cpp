#include <iostream>
#include <cstring>
#include <bank-account-system5.h>
using namespace std;

// Account Class Method Definition

Account::Account(int address, char *name, double balance)
	:address(address), balance(balance)
{
	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy(this->name, name);
}

Account::Account(const Account &copy)
	:address(copy.address), balance(copy.balance)
{
	int len = strlen(copy.name) + 1;
	this->name = new char[len];
	strcpy(this->name, copy.name);
}

bool Account::addBalance(double balance)
{
	this->balance += balance;
	return true;
}

const int Account::getAddress() const
{
	return this->address;
}

const char* Account::getName() const
{
	return this->name;
}

void Account::showInfo() const
{
	cout << "계좌주소 : " << this->address << endl;
	cout << "고객이름 : " << this->name << endl;
	cout << "계좌잔액 : " << this->balance << endl;
}

Account::~Account()
{
	delete []name;
}

// AccountHandler Class Method Definition 

AccountHandler::AccountHandler()
	: num(0) {}

void AccountHandler::makeAccount()
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

	// 포인터 변수에 Entity 객체를 생성하여 그 주소를 저장하고
	Account* pAccount = new Account(address, name, balance);
	// 포인터 변수를 핸들러 객체에 포함시킨다.
	this->pAccounts[this->num++] = pAccount;
}

void AccountHandler::deposit()
{
	int address;
	double balance;

	cout << "입금계좌주소 : ";
	cin >> address;

	int i;
	// 전역변수에서 this->pAccounts로 변경
	for(i = 0; i < this->num &&
		!(this->pAccounts[i]->getAddress() 
		== address); i++);
	// 전역변수에서 this->num으로 변경
	if(i == this->num) {
		cout << "찾으시는 계좌가 없습니다. 다시 시도해 주세요." << endl;
		return;
	}

	cout << "입금금액 : ";
	cin >> balance;

	// 전역변수에서 this->pAccounts로 변경
	if(this->pAccounts[i]->addBalance(balance))
		cout << this->pAccounts[i]->getName() << " 에게 " 
		<< balance << " 원 입금 완료 !" << endl;
}

void AccountHandler::withdrawal()
{
	int address;
	double balance;

	cout << "출금계좌주소 : ";
	cin >> address;

	int i;
	// 전역변수에서 this->pAccounts로 변경
	for(i = 0; i < this->num &&
		!(this->pAccounts[i]->getAddress()
		== address); i++);

	// 전역변수에서 this->num으로 변경
	if(i == this->num) {
		cout << "찾으시는 계좌가 없습니다. 다시 시도해 주세요." << endl;
		return;
	}

	cout << "출금금액 : ";
	cin >> balance;

	// 전역변수에서 this->pAccounts로 변경
	if(this->pAccounts[i]->addBalance(-balance))
		cout << this->pAccounts[i]->getName() << " 계좌에서 " 
		<< balance << " 원 출금 완료 !" << endl;
}

void AccountHandler::allPrint() {
	cout << "**전체 계좌정보 출력**" << endl;
	// 전역변수에서 this->num으로 변경
	for(int i=0; i < this->num; i++) {
		cout << "-" << i+1 << "번째 고객정보" << endl;
		// 전역변수에서 this->pAccounts로 변경
		this->pAccounts[i]->showInfo();
	}
}

void AccountHandler::showMenu()
{
	cout << "\n";
	cout << "**MENU**" << endl;
	cout << "1. 계좌 개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}
