#include <iostream>
using namespace std;

class SoSimple
{
public:
	static int simObjCnt;
public: // 불필요하지만 변수와 함수의 구분을 목적으로 사용하기도 함
	SoSimple() {
		simObjCnt++;
	}
};
int SoSimple::simObjCnt=0;

int main(void)
{
	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
	SoSimple sim1;
	SoSimple sim2;

	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
	cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;
	cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;
	return 0;
}

/*
1. SoSimple::simObjCnt, sim1.simObjCnt, sim2.simObjCnt 모두 다 같은 static public member 변수를 참조하고 있다.
2. public으로 선언이 되면, 클래스의 이름을 이용해서 호출또한 가능하다.
*/
