/*
1. 32라인 이니셜라이저의 효과 : Rectangle객체를 생성자로 만들어내는 과정에서 멤버변수인 Point객체의 생성자를 사용.
2. 객체의 생성과정
  1> 메모리 공간 할당
  2> 이니셜라이저를 통한 멤버변수(또는 객체)의 초기화
  3> 생성자의 몸체부분 실행
3. 멤버 이니셜라이저는 객체가 아닌 멤버의 초기화에도 사용할 수 있다.
  ex>
  class SoSimple
  {
  private:
    int num1;
    int num2;
  public:
    SoSimple(int n1, int n2) : num1(n1)
    {
      num2 = n2;
    }
  }
4. 이니셜라이저를 통한 초기화는 멤버변수 또는 객체의 생성과 동시에 초기화를 하기 때문에,
  1> 성능상의 이점이 있으며,
  2> const멤버의 초기화를 위해서는 이니셜라이저를 통한 초기화가 필수적이다.
  3> const멤버와 마찬가지로 참조자 멤버변수 또한 이니셜라이저를 통한 초기화가 필수적이다. 참조자 또한 선언과 동시에 초기확가 이루어져야하기 때문이다.
*/

#include <iostream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2)
  :upLeft(x1, y1), lowRight(x2, y2) //멤버변수가 객체인 경우 초기화 하는 방법 : 멤버 이니셜라이저 (initializer)
{
  //empty -> 이상하게 여길 필요 없다.
}

void Rectangle::ShowRecInfo() const {
  cout << "upLeft : (" << upLeft.GetX() << ", " << upLeft.GetY() << ')' << endl;
  cout << "lowRight : (" << lowRight.GetX() << ", " << lowRight.GetY() << ')' << endl;
}
