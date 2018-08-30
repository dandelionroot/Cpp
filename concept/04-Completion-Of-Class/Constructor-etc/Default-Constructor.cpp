/*
1. 생성자를 따로 정의하지 않은 클래스는 default constructor를 자동으로 삽입
2. 디폴트 생성자 : 인자를 받지 않으며, 내부적으로 아무런 일도 하지 않음
3. 모든 객체의 생성시 하나의 생성자가 호출되어야 한다.
4. malloc 함수호출 시 크기정보만 바이트 단위로 전달되기 때문에 생성자가 호출되지 않는다.
5. 디폴트 생성자는 생성자가 하나도 정의되어 있지 않았을 때만 삽입이 된다.
*/

#include <iostream>
using namespace std;

class AAA
{
private:
  int num;
public:
  /*AAA(){}*/
  int GetNum { return num; }
};
