#include <iostream>
using namespace std;

class CountryArea
{
public:
	const static int RUSSIA = 1707540;
	const static int CANADA = 998457;
	const static int CHINA = 957290;
	const static int SOUTH_KOREA = 9922;
};

int main(void)
{
	cout << "러시아 면적: " << CountryArea::RUSSIA << "km" << endl;
	cout << "캐나다 면적: " << CountryArea::CANADA << "km" << endl;
	cout << "중국 면적: " << CountryArea::CHINA << "km" << endl;
	cout << "한국 면적: " << CountryArea::SOUTH_KOREA << "km" << endl;
	return 0;
}

/*
1. 원래 const 멤버변수는 생성자의 이니셜라이저를 통한 초기화만 가능하지만, const static은 위와같이 선언과 동시에 초기화가 가능하다.
2. 이러한 클래스를 설계하면 객체의 생성 없이도 멤버변수에 접근이 가능하다.
*/
