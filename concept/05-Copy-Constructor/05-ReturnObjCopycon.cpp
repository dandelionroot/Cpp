#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int num) : num(num) {}
	SoSimple(const SoSimple &copy) : num(copy.num)
	{
		cout << "called SoSimple(const SoSimple &copy)" << endl;
	}
	SoSimple& AddNum(int n)
	{
		this->num += n;
		return *this;
	}
	void ShowData()
	{
		cout << "num : " << this->num << endl;
	}
};

SoSimple SimpleFuncObj(SoSimple ob) //복사생성자 호출1
{
	cout << "return 이전" << endl;
	return ob; //복사생성자 호출2 (새로운 임시객체를 만들어서 SoSimple 임시객체(ob) 실행 후 임시객체 반환
}

int main(void)
{
	SoSimple obj(7);
	SimpleFuncObj(obj).AddNum(30).ShowData();
	obj.ShowData();
	return 0;
}

/*
SimpleFuncObj(obj) -> SoSimple ob = obj -> SoSimple ob(obj)
SoSimple 공간할당과 함께 새로운 ob객체를 생성하고 ob가 주체가 되어 복사생성자 호출 (obj를 참조하는 것이 아님)
SimpleFuncObj(obj).AddNum(30) -> ob.AddNum(30) -> ob에 30을더하고 ob의 참조자 반환 -> ShowData() -> 37
obj는 그대로 있음
*/
