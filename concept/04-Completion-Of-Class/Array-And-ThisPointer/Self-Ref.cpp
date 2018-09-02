/*
1. 이 예제에서 생성된 NumClass는 단 하나이며, ref라는 NumClass참조자가 obj를 참조하고 있다.
*/

#include <iostream>
using namespace std;

class NumClass
{
private:
	int num;
public:
	NumClass(int num) : num(num) {}
	NumClass& Adder(int add)
	{
		num += add;
		return *this; // this포인터를 반환하는것이 아니라 객체자체를 반환
	}
	NumClass& Show()
	{
		cout << "num : " << this->num << endl;
		return *this;
	}
};

int main(void)
{
	NumClass obj(3);
	NumClass &ref = obj.Adder(2);

	obj.Show();
	ref.Show();

	ref.Adder(1).Show().Adder(2).Show();

	return 0;
}
