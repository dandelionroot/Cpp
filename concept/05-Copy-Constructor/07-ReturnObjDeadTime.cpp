#include <iostream>
using namespace std;

class SoSimple
{
private :
	int num;
public :
	SoSimple(int n) : num(n)
	{
		cout << "New Object : " << this << endl;
	}
	SoSimple(const SoSimple& copy) : num(copy.num)
	{
		cout << "New Copy obj : " << this << endl;
	}
	~SoSimple()
	{
		cout << "Destroy obj : " << this << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob)
{
	cout << "Parm ADR : " << &ob << endl;
	return ob;
}

int main(void)
{
	SoSimple obj(7);
	SimpleFuncObj(obj);

	cout << endl;
	SoSimple tempRef = SimpleFuncObj(obj); // 반환되는 객체를 가지고 대입연산을 하는것처럼 보이지만, 추가를 객체를 생성하지 않고 반환되는 임시객체에 tempRef라는 이름을 할당하고 있음.
	cout << "Return Obj " << &tempRef << endl;
	return 0;
}
