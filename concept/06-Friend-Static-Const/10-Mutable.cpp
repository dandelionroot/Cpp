#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	mutable int num2;
public:
	SoSimple(int n1, int n2)
		: num1(n1), num2(n2) { }
	void ShowSimpleData() const {
		cout << num1 << ", " << num2 << endl;
	}
	void CopyToNum2() const
	{
		num2 = num1;
	}
};

int main(void)
{
	SoSimple sim1(1,2);
	sim1.ShowSimpleData();
	sim1.CopyToNum2();
	sim1.ShowSimpleData();
	return 0;
}

// mutable은 const 함수에 예외를 둘 때 사용
// mutable은 const의 의미를 해칠수 있으므로 사용 자제
