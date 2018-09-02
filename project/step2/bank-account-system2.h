enum
{
	MAKE = 1, DEPOSIT, WITHDRAW, PRINT, EXIT 
};

void showMenu();

class Account
{
private:
	int address;
	char *name;
	double balance;
public:
	Account(int address, char *name, double balance);// 초기 balance는 0
	bool AddBalance(double balance);
	const int GetAddress() const;
	const char *GetName() const;
	const double GetBalance() const;
};

Account *makeAccount();

void deposit();

void withdrawal();

void allPrint();
