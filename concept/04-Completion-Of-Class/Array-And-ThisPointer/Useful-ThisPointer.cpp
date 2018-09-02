/*
1. this 포인터를 활용하면 매개변수와 멤버변수의 이름을 다르게 하려고 고생할 필요가 없다.
2. this포인터가 이를 알아서 구분해 주기 때문이다.
3. 멤버 이니셜라이저를 이용한 초기화는 알아서 구분을 해준다. 즉, 16행과 22행의 생성자는 동일한 기능을 한다.
*/

#include <iostream>
using namespace std;

class TwoNumber
{
private:
	int num1;
	int num2;
public:
	TwoNumber(int num1, int num2)
	{
		this->num1 = num1;
		this->num2 = num2;
	}
	/*
	TwoNumber(int num1, int num2) : num1(num1), num2(num2) {}
	void ShowNumbers() const
	{
		cout << "num1 : " << this->num1 << ", ";
		cout << "num2 : " << this->num2 << endl;
	}
	*/
};

int main(void)
{
	TwoNumber two(2, 4);
	two.ShowNumbers();

	return 0;
}
