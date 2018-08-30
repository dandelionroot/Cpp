#include <iostream>
using namespace std;

class AAA
{
private:
  int num;
public:
  AAA():num(0) {}
  AAA& CreateInitObj(int n) const
  {
    AAA *ptr = new AAA(n); //AAA객체의 메모리주소
    return *ptr; //AAA객체 그자체
  }
  void ShowNum() const { cout << num << endl; }
private:
  AAA(int n) : num(n) {} //프라이빗 생성자(메서드에 의한 객체생성만 가능)
};

int main(void)
{
  AAA base;
  base.ShowNum();

  AAA &obj1 = base.CreateInitObj(3); //힙에 할당된 메모리 공간은 변수로 간주하여, 참조자를 통한 참조가 가능하다.
  obj1.ShowNum();

  AAA &obj2 = base.CreateInitObj(12);//힙에 할당된 메모리 공간은 변수로 간주하여, 참조자를 통한 참조가 가능하다.
  obj2.ShowNum();

  delete &obj1;
  delete &obj2;
  return 0;
}
