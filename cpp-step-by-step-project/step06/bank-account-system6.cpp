#include <iostream>
#include <cstring>
#include <bank-account-system6.h>
using namespace std;

/*
    Account Class Method Definition
    * Base Class of NormalAccount and HighCreditAccount
*/
Account::Account(const int address, const char *name, const double balance)
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

const bool Account::addBalance(const double balance)
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

/*
    NormalAccount Class Method Definition
    * Base Class : Account
*/

// Base Class의 생성자를 재활용 할 수 있다.
NormalAccount::NormalAccount(const int address,
    const char *name, const double balance,
    const double intRatio) : Account(address, name, balance),
    intRatio(intRatio) {}

// Base Class의 복사생성자를 재활용 할 수 있다.
NormalAccount::NormalAccount(const NormalAccount &copy)
    : Account(copy), intRatio(copy.intRatio) {}

const bool NormalAccount::addBalance(const double balance) {
    bool succeed = false;
    // Base Class의 기존함수 호출 후
    succeed = Account::addBalance(balance);

    // Derived Class의 추가 멤버함수에 대한 처리(이자 추가)
    // 출금인 경우에는 이자를 적용하지 않음
    if(balance > 0)
        Account::addBalance(balance * this->intRatio / 100.0);
    
    return succeed;
}

void NormalAccount::showInfo() const {
    // Base Class의 기존함수 호출 후
    Account::showInfo();
    // Derived Class의 추가 멤버함수에 대한 처리
    cout << "이자율 : " << this->intRatio << endl;
}

/*
    HighCreditAccount Class Method Definition
    * Base Class : NormalAccount
*/

// Base Class의 생성자를 재활용 할 수 있다.
HighCreditAccount::HighCreditAccount(const int address,
    const char *name, const double balance, const double intRatio,
    const char grade) : NormalAccount(address, name, balance, intRatio),
    grade(grade) {}

// Base Class의 복사생성자를 재활용 할 수 있다.
HighCreditAccount::HighCreditAccount(const HighCreditAccount &copy)
    : NormalAccount(copy), grade(copy.grade) {}

const bool HighCreditAccount::addBalance(const double balance) {
    double plusRatio = 0;
    bool succeed = false;

    // Base Class의 기존함수 호출 후
    succeed = NormalAccount::addBalance(balance);

    // Derived Class의 추가 멤버함수에 대한 처리
    // 출금인 경우에는 이자를 적용하지 않음
    if(balance > 0) {
        switch(this->grade) {
            case 'A':
                plusRatio = 7.0;
                break;
            case 'B':
                plusRatio = 4.0;
                break;
            case 'C':
                plusRatio = 2.0;
                break;
            default:
                break;
        }
        // 이자를 중복으로 지급하지 않기 위해 Account Class의 addBalance 사용
        Account::addBalance(balance * plusRatio / 100.0);
    }

    return succeed;
}

void HighCreditAccount::showInfo() const {
    // Base Class의 기존함수 호출 후
    NormalAccount::showInfo();
    // Derived Class의 추가 멤버함수에 대한 처리
    cout << "고객등급 : " << this->grade << endl;
}

/*
    AccountHandler Class Method Definition
    * 유일하게 변경한 부분 : makeAccount 메서드에서 계좌종류별로 객체를 생성하는 부분
    * 단독적으로 address, name, balance에 대해 처리할 경우
    * Base Class의 기존 메서드를 사용해도 문제가 없음
    * intRatio, grade와 연관된 처리는 기존 메서드를 virtual로 선언하고
    * Derived Class의 virtual 메서드를 오버라이딩 하였으므로 역시 문제가 없음
*/ 

AccountHandler::AccountHandler()
	: num(0) {}

void AccountHandler::makeAccount()
{
    Account* pAccount;
    int kindOfAcc = 0;
	int address;
	char name[15];
	double balance;
    double intRatio;
    char grade;

    cout << "[계좌종류선택]" << endl;
    cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
    cout << "선택 : ";
    cin >> kindOfAcc;

    switch(kindOfAcc) {
        case 1:
            cout << "[보통예금계좌 개설]" << endl;
            break;
        case 2:
            cout << "[신용신뢰계좌 개설]" << endl;
            break;
        default:
            cout << "1, 2중에서 선택해 주세요." << endl;
            return;
    }

	cout << "계좌주소 : ";
	cin >> address;
	cout << "성함 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> balance;
    cout << "이자율 : ";
    cin >> intRatio;

    if(kindOfAcc == 2) {
        cout << "고객등급 : ";
        cin >> grade;
    }

    switch(kindOfAcc) {
        case 1:
            pAccount = new NormalAccount(address, name,
                balance, intRatio);
            break;
        case 2:
            pAccount = new HighCreditAccount(address, name,
                balance, intRatio, grade);
            break;
        default:
            break;
    }

    this->pAccounts[this->num++] = pAccount;

}

void AccountHandler::deposit() const
{
	int address;
	double balance;

	cout << "입금계좌주소 : ";
	cin >> address;

	int i;
	for(i = 0; i < this->num &&
		!(this->pAccounts[i]->getAddress() 
		== address); i++);
	if(i == this->num) {
		cout << "찾으시는 계좌가 없습니다. 다시 시도해 주세요." << endl;
		return;
	}

	cout << "입금금액 : ";
	cin >> balance;

    // addBalance 메서드를 virtual로 선언했으므로
    // pAccount의 타입에 관계없이 실제 가리키는 객체의 메서드 호출
	if(this->pAccounts[i]->addBalance(balance))
		cout << this->pAccounts[i]->getName() << " 에게 " 
		<< balance << " 원 입금 완료 !" << endl;
}

void AccountHandler::withdrawal() const
{
	int address;
	double balance;

	cout << "출금계좌주소 : ";
	cin >> address;

	int i;
	for(i = 0; i < this->num &&
		!(this->pAccounts[i]->getAddress()
		== address); i++);

	if(i == this->num) {
		cout << "찾으시는 계좌가 없습니다. 다시 시도해 주세요." << endl;
		return;
	}

	cout << "출금금액 : ";
	cin >> balance;

    // addBalance 메서드를 virtual로 선언했으므로
    // pAccount의 타입에 관계없이 실제 가리키는 객체의 메서드 호출
	if(this->pAccounts[i]->addBalance(-balance))
		cout << this->pAccounts[i]->getName() << " 계좌에서 " 
		<< balance << " 원 출금 완료 !" << endl;
}

void AccountHandler::allPrint() const {
	cout << "**전체 계좌정보 출력**" << endl;
	for(int i=0; i < this->num; i++) {
		cout << "-" << i+1 << "번째 고객정보" << endl;
        // showInfo 메서드를 virtual로 선언했으므로
        // pAccount의 타입에 관계없이 실제 가리키는 객체의 메서드 호출
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
