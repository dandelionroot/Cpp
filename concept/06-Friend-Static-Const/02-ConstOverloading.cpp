#include <iostream>
using namespace std;

class SoSimple {
private:
	int num;
public:
	SoSimple(int n):num(n) {}
	SoSimple& AddNum(int n) {
		this->num += n;
		return *this;
	}
	void SimpleFunc() {
		cout << "SimpleFunc: " << this->num << endl;
	}
	void SimpleFunc() const {
		cout << "const SimpleFunc: " << this->num << endl;
	}
};

void YourFunc(const SoSimple &obj) {
	obj.SimpleFunc();
}

int main(void) {
	SoSimple obj1(2);
	const SoSimple obj2(7);

	obj1.SimpleFunc();
	obj2.SimpleFunc();

	YourFunc(obj1);
	YourFunc(obj2);
	return 0;
}

/*
1. const의 유무도 함수 오버로딩의 기준이 된다.
2. 객체에서 메서드 호출 시 객체가 const인지 아닌지에 관계없이 const함수가 호출된다.
3. 일반 함수 호출 시에는 const객체가 인자로 전달되었을때만 const함수를 호출한다.
*/
