/*
1. this는 객체의 주소를 가지고있는 포인터이다.
*/

#include <iostream>
using namespace std;

class Simple
{
private:
	int num;
public:
	Simple(int mynum) : num(mynum) { }
	void ShowSimple() const
	{
		cout << "data : " << num << ",";
		cout << "address : " << this << endl;
	}
	const Simple *GetAddress() const //반환형에 조심
	{
		return this;
	}
};

int main(void)
{
	Simple sim1(100);
	const Simple *ptr1 = sim1.GetAddress();
	ptr1->ShowSimple(); // this를 가리키는 포인터로도 객체의 퍼블릭함수 호출이 가능하다.

	Simple sim2(200);
	const Simple *ptr2 = sim2.GetAddress();
	ptr2->ShowSimple();

	return 0; 
}
