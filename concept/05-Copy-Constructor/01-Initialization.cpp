#include <iostream>
using namespace std;

/*
int num = 20;
int %ref = num;
*/

/*
int num(20);
int &ref(num);
*/

class SoSimple
{
private:
	int num1;
	int num2;
public:
	SoSimple(int n1, int n2) : num1(n1), num2(n2)
	{}
	SoSimple(const SoSimple &copy) : num1(copy.num1), num2(copy.num2)
	{
		cout << "Called SoSimple(SoSimpled &copy)" << endl;
	}
	void ShowSimpleData()
	{
		cout << this->num1 << endl;
		cout << this->num2 << endl;
	}
};

int main(void)
{
	SoSimple sim1(15, 20);
	cout << "생성 및 초기화 직전" << endl;
	SoSimple sim2 = sim1; // Sosimple sim2(sim1); 으로 변환
	cout << "생성 및 초기화 직후" << endl;
	sim2.ShowSimpleData();
	return 0;
}

/*
1. 37라인의 복사 생성자를 정의하지 않으면, 디폴트 복사 생성자가 자동으로 삽입된다.
2. 37라인의 묵시적 변환을 허용하고 싶지 않으면, 함수 정의 앞에 explicit을 붙여주면 된다.
3. 묵시적 변환은 복사 생성자에서만 일어나는게 아니라, 전달인자가 하나인 생성자에서는 전부 일어난다.
*/
