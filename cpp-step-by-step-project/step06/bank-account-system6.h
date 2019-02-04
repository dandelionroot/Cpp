// Entity Class
class Account
{
private:
	int address;
	char *name;
	double balance;
public:
	Account(const int address, const char *name,
        const double balance);
	Account(const Account &copy);
	virtual const bool addBalance(const double balance);
	const int getAddress() const;
	const char* getName() const;
	virtual void showInfo() const;
	~Account();
};

// Entity Class
// Base Class : Account
class NormalAccount : public Account
{
private:
    double intRatio;
public:
    NormalAccount(const int address, const char *name,
        const double balance, const double intRatio);
    NormalAccount(const NormalAccount &copy);
    virtual const bool addBalance(const double balance);
    virtual void showInfo() const;
    ~NormalAccount();
};

// Entity Class
// Base Class : NormalAccount
class HighCreditAccount : public NormalAccount
{
private:
    char grade;
public:
    HighCreditAccount(const int address, const char *name,
        const double balance, const double intRatio,
        const char grade);
    HighCreditAccount(const HighCreditAccount &copy);
    virtual const bool addBalance(const double balance);
    virtual void showInfo() const;
    ~HighCreditAccount();
};

enum { MAKE = 1, DEPOSIT, WITHDRAW, PRINT, EXIT };

// Control Class
class AccountHandler
{
private:
	Account* pAccounts[100];
	int num;
public:
	AccountHandler();
	void makeAccount();
	void deposit() const;
	void withdrawal() const;
	void allPrint() const;
	static void showMenu();
};
