#define NAME_LENGTH 15
#define ACCOUNT_NUMBER 50

typedef struct AccountType {
	int id;
	char name[NAME_LENGTH];
	double value;
} Account;

enum {MAKE=1, DEPOSIT, WITHDRAW, PRINT, EXIT};

void showMenu();

void makeAccount();

void deposit();

void withdrawal();

void allPrint();
