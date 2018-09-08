#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char * name;
	int age;
public:
	Person(char * myname, int myage)
	{
		int len = strlen(myname) + 1;
		this->name = new char[len];
		strcpy(this->name, myname);
		age = myage;
	}
	/*
	Person(Person &copy) : age(copy.age)
	{
		this->name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}
	*/
	void ShowPersonInfo() const
	{
		cout << "이름 : " << this->name << endl;
		cout << "나이 : " << this->age << endl;
	}
	~Person()
	{
		delete []name; // name포인터가 가리키는 배열공간을 삭제
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2 = man1; // man2(man1) 으로 묵시적 변환
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}

/*
40 : 디폴트 복사 생성자는 멤버 대 멤버의 단순한 얕은 복사 수행, 따라서 man1의 name과 man2의 name포인터는 같은 메모리공간을 참조하게 됨.
-> 소멸자가 두 번 호출되면 문제가 된다.
18 ~ 24 : 디폴트 복사 생성자의 얕은 복사의 문제점을 해결하기 위한 깊은 복사 생성자의 정의.
-> 멤버변수 age의 멤버 대 멤버 복사, 메모리 공간 할당후 문자열 복사하고 메모리 주소값을 name에 저장.
*/
