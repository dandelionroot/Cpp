#include <iostream>
#include <cstring>
#include <bank-account-system4.h>
using namespace std;

Account* pAccount[100]; // 100명의 Account주소를 저장할 수 있는 포인터배열
int accum = 0; // 개설된 계좌 수 및 앞으로 생성할 계좌의 위치

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
	:address(address), balance(balance) // 멤버 이니셜라이저로 계좌주소와 잔액을 초기화
{
	int len = strlen(name) + 1;
	this->name = new char[len];
	strcpy(this->name, name); // 성함 정보를 char형 배열에 동적할당하여 저장
}

Account::Account(const Account &copy)
	:address(copy.address), balance(copy.balance)
{
	int len = strlen(copy.name) + 1;
	this->name = new char[len];
	strcpy(this->name, copy.name);
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
	delete []name; // 동적할당한 성함정보의 char배열을 소멸
}

Account *makeAccount()
{
	int address;
	char name[15];
	double balance; // Account 생성자에게 넘겨줄 지역변수 생성

	cout << "계좌주소 : ";
	cin >> address;
	cout << "성함 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> balance;

	Account* pReturn = new Account(address, name, balance); // Account클래스를 동적 할당하고 반환된 주소를 pReturn에 저장
	pAccount[accum] = pReturn; // 포인터 배열의 적절한 위치에 있는 요소가 pRreturn을 가리키도록 함
	accum++; // 개설된 계좌수 증가
	return pReturn;
}

void deposit()
{
	int address;
	double balance;

	cout << "입금계좌주소 : ";
	cin >> address;

	int i;
	for(i = 0; i < accum; i++) { // 입력된 계좌주소의 위치찾기
		if(pAccount[i]->GetAddress() == address)
			break;
	}

	if(i == accum) { // 일치하는 주소가 없다면 i는 accum과 같아질것이므로
		cout << "찾으시는 계좌가 없습니다. 다시 시도해 주세요." << endl;
		return;
	}

	cout << "입금금액 : ";
	cin >> balance;

	if(pAccount[i]->AddBalance(balance)) // AddBalance함수가 성공했다면
		cout << pAccount[i]->GetName() << " 에게 " 
		<< balance << " 원 입금 완료 !" << endl;
}

void withdrawal() // deposit()과 유사
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

	if(pAccount[i]->AddBalance(-balance)) // balance에 -만 추가
		cout << pAccount[i]->GetName() << " 계좌에서 " 
		<< balance << " 원 출금 완료 !" << endl;
}

void allPrint() {
	cout << "**전체 계좌정보 출력**" << endl;
	for(int i=0; i<accum; i++) { // 전체 계좌정보를 처음부터 하나씩 출력
		cout << "-" << i+1 << "번째 고객정보" << endl;
		pAccount[i]->ShowInfo();
	}
}
