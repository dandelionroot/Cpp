#include &lt;iostream&gt;
#include &lt;cstring&gt;
#include &lt;bank-account-system5.h&gt;
using namespace std;

// Account Class Method Definition

Account::Account(int address, char *name, double balance)
	:address(address), balance(balance)
{
	int len = strlen(name) + 1;
	this-&gt;name = new char[len];
	strcpy(this-&gt;name, name);
}

Account::Account(const Account &amp;copy)
	:address(copy.address), balance(copy.balance)
{
	int len = strlen(copy.name) + 1;
	this-&gt;name = new char[len];
	strcpy(this-&gt;name, copy.name);
}

bool Account::addBalance(double balance)
{
	this-&gt;balance += balance;
	return true;
}

const int Account::getAddress() const
{
	return this-&gt;address;
}

const char* Account::getName() const
{
	return this-&gt;name;
}

void Account::showInfo() const
{
	cout &lt;&lt; "계좌주소 : " &lt;&lt; this-&gt;address &lt;&lt; endl;
	cout &lt;&lt; "고객이름 : " &lt;&lt; this-&gt;name &lt;&lt; endl;
	cout &lt;&lt; "계좌잔액 : " &lt;&lt; this-&gt;balance &lt;&lt; endl;
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

	cout &lt;&lt; "계좌주소 : ";
	cin &gt;&gt; address;
	cout &lt;&lt; "성함 : ";
	cin &gt;&gt; name;
	cout &lt;&lt; "입금액 : ";
	cin &gt;&gt; balance;

	// 포인터 변수에 Entity 객체를 생성하여 그 주소를 저장하고
	Account* pAccount = new Account(address, name, balance);
	// 포인터 변수를 핸들러 객체에 포함시킨다.
	this-&gt;pAccounts[this-&gt;num++] = pAccount;
}

void AccountHandler::deposit()
{
	int address;
	double balance;

	cout &lt;&lt; "입금계좌주소 : ";
	cin &gt;&gt; address;

	int i;
	// 전역변수에서 this-&gt;pAccounts로 변경
	for(i = 0; i &lt; this-&gt;num &amp;&amp;
		!(this-&gt;pAccounts[i]-&gt;getAddress() 
		== address); i++);
	// 전역변수에서 this-&gt;num으로 변경
	if(i == this-&gt;num) {
		cout &lt;&lt; "찾으시는 계좌가 없습니다. 다시 시도해 주세요." &lt;&lt; endl;
		return;
	}

	cout &lt;&lt; "입금금액 : ";
	cin &gt;&gt; balance;

	// 전역변수에서 this-&gt;pAccounts로 변경
	if(this-&gt;pAccounts[i]-&gt;addBalance(balance))
		cout &lt;&lt; this-&gt;pAccounts[i]-&gt;getName() &lt;&lt; " 에게 " 
		&lt;&lt; balance &lt;&lt; " 원 입금 완료 !" &lt;&lt; endl;
}

void AccountHandler::withdrawal()
{
	int address;
	double balance;

	cout &lt;&lt; "출금계좌주소 : ";
	cin &gt;&gt; address;

	int i;
	// 전역변수에서 this-&gt;pAccounts로 변경
	for(i = 0; i &lt; this-&gt;num &amp;&amp;
		!(this-&gt;pAccounts[i]-&gt;getAddress()
		== address); i++);

	// 전역변수에서 this-&gt;num으로 변경
	if(i == this-&gt;num) {
		cout &lt;&lt; "찾으시는 계좌가 없습니다. 다시 시도해 주세요." &lt;&lt; endl;
		return;
	}

	cout &lt;&lt; "출금금액 : ";
	cin &gt;&gt; balance;

	// 전역변수에서 this-&gt;pAccounts로 변경
	if(this-&gt;pAccounts[i]-&gt;addBalance(-balance))
		cout &lt;&lt; this-&gt;pAccounts[i]-&gt;getName() &lt;&lt; " 계좌에서 " 
		&lt;&lt; balance &lt;&lt; " 원 출금 완료 !" &lt;&lt; endl;
}

void AccountHandler::allPrint() {
	cout &lt;&lt; "**전체 계좌정보 출력**" &lt;&lt; endl;
	// 전역변수에서 this-&gt;num으로 변경
	for(int i=0; i &lt; this-&gt;num; i++) {
		cout &lt;&lt; "-" &lt;&lt; i+1 &lt;&lt; "번째 고객정보" &lt;&lt; endl;
		// 전역변수에서 this-&gt;pAccounts로 변경
		this-&gt;pAccounts[i]-&gt;showInfo();
	}
}

void AccountHandler::showMenu()
{
	cout &lt;&lt; "\n";
	cout &lt;&lt; "**MENU**" &lt;&lt; endl;
	cout &lt;&lt; "1. 계좌 개설" &lt;&lt; endl;
	cout &lt;&lt; "2. 입금" &lt;&lt; endl;
	cout &lt;&lt; "3. 출금" &lt;&lt; endl;
	cout &lt;&lt; "4. 계좌정보 전체 출력" &lt;&lt; endl;
	cout &lt;&lt; "5. 프로그램 종료" &lt;&lt; endl;
}
