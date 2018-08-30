/*
1. 참조자 멤버변수(객체)를 초기화 하려면 멤버 이니셜라이저가 필수적이다 -> 24행
*/

#include <iostream>
using namespace std;

class AAA {
public:
  AAA () {
    cout << "empty object" << endl;
  }
  void ShowYourName() {
    cout << "I'm class AAA" << endl;
  }
};

class BBB
{
private:
  AAA &ref;
  const int &num;
public:
  BBB(AAA &r, const int &n) : ref(r), num(n) {} //AAA r, const int n을 매개변수로 해도 상관없지만 주소에 접근한다는걸 명확히 밝힘
  void ShowYourName()
  {
    ref.ShowYourName();
    cout << "and" << endl;
    cout << "I ref num" << num << endl;
  }
};

int main(int argc, char const *argv[]) {
  AAA obj1;
  BBB obj2(obj1, 20);
  obj2.ShowYourName();
  return 0;
}
