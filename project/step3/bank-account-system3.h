enum // 인터페이스 구성
{
	MAKE = 1, DEPOSIT, WITHDRAW, PRINT, EXIT 
};

void showMenu(); // 사용자에게 수행할 수 있는 메뉴를 보여줌

class Account // 개개인의 계좌정보를 가진 클래스
{
private:
	int address; // 계좌주소
	char *name; // 성함
	double balance; // 잔액
public:
	Account(int address, char *name, double balance); // 생성자
	Account(Account &copy);
	bool AddBalance(double balance); // 잔액을 balance만큼 더함
	const int GetAddress() const; // 계좌주소를 얻음
	const char *GetName() const; // 성함을 얻음
	void ShowInfo() const; // 해당 계좌정보를 출력
	~Account(); // 소멸자
};

Account *makeAccount(); // 계좌 생성

void deposit(); // 입금

void withdrawal(); // 출금

void allPrint(); // 전체 계좌정보를 출력
