#include <iostream>
#include "Point.h"

using namespace std;

Point::Point(const int &xpos, const int &ypos) {
  x = xpos;
  y = ypos;
}

int Point::GetX() const { return x; }

int Point::GetY() const { return y; }

bool Point::SetX(int xpos) {
  if(0 > xpos || xpos > 100) { // 제한된 방법으로의 접근만 허용함으로써 잘못된 값이 저장되지 않도록, 실수를 했을 때 실수가 쉽게 발견되도록 해야한다 -> 정보은닉(Information Hiding)의 목적
    cout << "invalid scope" << endl;
    return false;
  }
  x = xpos;
  return true;
}

bool Point::SetY(int ypos) {
  if(0 > ypos || ypos > 100) {
    cout << "invalid scope" << endl;
    return false;
  }
  y = ypos;
  return true;
}
