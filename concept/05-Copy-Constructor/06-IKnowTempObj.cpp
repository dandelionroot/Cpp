#include <iostream>
using namespace std;

class Temporary
{
private:
	int num;
public:
	Temporary(int num) : num(num)
	{
		cout << "create obj : " << this->num << endl;
	}
	~Temporary()
	{
		cout << "destroy obj : " << this->num << endl;
	}
	void ShowInfo() const
	{
		cout << "My name is : " << this->num << endl;
	}
};

int main(void)
{
	Temporary(100);
	cout << "********** after make !" << endl << endl;

	Temporary(200).ShowInfo();
	cout << "********** after make !" << endl << endl;

	const Temporary &ref = Temporary(300);
	cout << "********** end of main !" << endl << endl;
	return 0;
}

/*
1. 클래스 외부에서 객체의 멤버함수를 호출하기 위해 필요한 것은 다음 세가지 중 하나
	1> 객체에 붙여진 이름
	2> 객체의 참조 값(.으로 호출 - reference)
	3> 객체의 주소 값(->로 호출 - address)
2. 임시객체는 다음 행으로 넘어가면 바로 소멸된다.
3. 참조자에 의해 참조되는 임시객체는 바로 소멸되지 않는다.
*/
