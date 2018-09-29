#include <iostream>
using namespace std;

class SoSimple
{
private:
	static int simObjCnt;
public:
	SoSimple() {
		simObjCnt++;
		cout << simObjCnt << "번째 SoSimple 객체" << endl;
	}
};
int SoSimple::simObjCnt=0; // static 멤버변수의 초기화 방법(생성자로 초기화하는게 아닌 이유 ?)

class SoComplex
{
private:
	static int cmxObjCnt;
public:
	SoComplex() {
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
	SoComplex(SoComplex &copy) {
		cmxObjCnt++;
		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
	}
};
int SoComplex::cmxObjCnt=0;

int main(void)
{
	SoSimple sim1;
	SoSimple sim2;

	SoComplex com1;
	SoComplex com2 = com1;
	SoComplex();

	return 0;
}

/*
1. 멤버변수를 static으로 선언하면 모든 인스턴스에서 공유하게 된다.
2. 멤버변수이긴 하지만 객체외부에 저장되어 있다. 하지만 멤버변수처럼 참조가능
3. 생성 및 소멸의 시기도 전역변수와 동일하다.
4. static 멤버변수의 초기화는 생성자 안에서 진행하면 안된다. 만약 생성자 안에서 진행하면 static 멤버변수는 객체가 생성될때마다 초기화 될것이다.
5. static 멤버변수는 객체가 생성되기 전부터 이미 메모리공간의 할당이 이루어진 변수이다.
6. static 멤버변수만의 특별한 초기화 문법
-> int SoSimple::simObjCnt = 0;
*/
