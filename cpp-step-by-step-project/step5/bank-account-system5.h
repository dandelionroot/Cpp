/*
	6단계 진행시 Control Class에 const 선언(함수, 인자) 추가할 것
*/

enum
{
	MAKE = 1, DEPOSIT, WITHDRAW, PRINT, EXIT 
};

// Entity Class
class Account
{
private:
	int address;
	char *name;
	double balance;
public:
	Account(int address, char *name, double balance);
	Account(const Account &copy);
	bool addBalance(double balance);
	const int getAddress() const;
	const char* getName() const;
	void showInfo() const;
	~Account();
};

// Controll Class
class AccountHandler
{
private:
	Account* pAccounts[100];
	int num;
public:
	AccountHandler();
	void makeAccount();
	void deposit();
	void withdrawal();
	void allPrint();
	static void showMenu();
};
