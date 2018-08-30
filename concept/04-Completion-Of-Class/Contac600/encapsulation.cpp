/*
1.만약 코감기가 콧물, 재채기, 코막힘을 반드시 동시에 동반한다면, 아래 예제는 캡슐화의 실패이다.
2.만약 각각의 캡슐을 복용해야 하는 순서가 있다면, 아래 예제는 캡슐화의 실패이다.
3.따라서 캡슐들 간의 상호관계를 파악하고 encapsulation하여 사용자가 세부사항을 몰라도 부작용이 일어나지 않도록 해야한다.
*/

#include<iostream>
using namespace std;

class SinivelCap
{
public:
  void Take() const {
    cout << "콧물이 싹~ 납니다." << endl;
  }
};

class SneezeCap
{
public:
  void Take() const {
    cout << "재채기가 멎습니다." << endl;
  }
};

class SnuffleCap
{
public:
  void Take() const {
    cout << "코가 뻥 뚫립니다." << endl;
  }
};

class ColdPatient
{
public:
  void TakeSinivelCap(const SinivelCap &cap) const {
    cap.Take();
  }
  void TakeSneezeCap(const SneezeCap &cap) const {
    cap.Take();
  }
  void TakeSnuffleCap(const SnuffleCap &cap) const {
    cap.Take();
  }
};

int main(void) {
  SinivelCap scap;
  SneezeCap zcap;
  SnuffleCap ncap;

  ColdPatient sufferer;
  sufferer.TakeSinivelCap(scap);
  sufferer.TakeSneezeCap(zcap);
  sufferer.TakeSnuffleCap(ncap);
  return 0;
}
