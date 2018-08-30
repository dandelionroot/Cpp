#ifndef __POINT_H_
#define __POINT_H_

class Point
{
private: // private 멤버는 멤버함수에 의한 참조만 가능하다.
  int x;
  int y;
public:
  Point(const int &xpos, const int &ypos);
  int GetX() const; // const 선언
  int GetY() const;
  bool SetX(int xpos);
  bool SetY(int ypos);
};
#endif

/*
1. 정보은닉 : 멤버변수를 private로 선언하고,
해당 변수에 접근하는 함수를 별도로 정의해서, 안전한 형태로 멤버변수의 접근을 유도하는 것
2. 11 ~ 14 : 엑세스 함수, 사용하지 않더라도 그냥 정의해 두는게 좋다.
3. 함수의 const 선언 : 이 함수를 통해서 멤버변수에 저장된 값을 변경하지 않겠다 ! / const 함수 내에서는 const 함수만 호출해야 한다.
4. const참조자를 매개변수로 넘기는 함수는 const함수만 가능하다.
*/
