#include <iostream>
using namespace std;

void Counter()
{
	static int cnt;
	cnt++;
	cout << "Current cnt: " << cnt << endl;
}

int main(void)
{
	for(int i=0; i<10; ++i)
		Counter();
	return 0;
}

/*
1. c언어에서 static의 의미
	1> 전역변수로 선언된 경우 : 이 파일 내에서만 참조를 허용하겠다.
	2> 함수 내 선언된 경우 : 한번만 초기화되고, 함수를 빠져나가도 소멸되지 않는다.
*/
