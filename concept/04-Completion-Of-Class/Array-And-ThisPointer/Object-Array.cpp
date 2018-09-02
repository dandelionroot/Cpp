/*
1. 객체 배열을 라인 54와 같이 선언할 수 있다.
2. 하지만 객체 배열을 생성할 때 객체 각각마다 원하는 생성자를 호출할 수 없다.
3. 그래서 class_name () {...} 형태의 생성자가 정의되어 있어야 한다. --> 인자를 전달하지 못한다.
4. 따라서 별도의 초기화 함수를 이용하여 초기화 시켜주어야 한다.

*/

#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
  char *name;
  int age;
public:
  Person(char *myname, int myage)
  {
    int len = strlen(myname) + 1;
    name = new char[len]; //myname을 그대로 이어받는것이 아니라 새로운 공간을 할당하고
    strcpy(name, myname); //값만 넘겨받음
    age = myage; //값만 넘겨받음
  }
  Person()
  {
    name = NULL;
    age = 0;
    cout << "called Person()" << endl;
  }
  void SetPersonInfo(char *myname, int myage)
  {
    name = myname;
    age = myage;
  }
  void ShowPersonInfo() const
  {
    cout << "이름 : " << name << "," << endl;
    cout << "나이 : " << age << endl;
  }
  ~Person()
  {
    delete []name; // name을 삭제하는 이유는 name만 동적으로 할당되었기 때문이다.
    cout << "called destructor !" << endl;
  }
};

int main(void)
{
  char namestr[100];
  char *nameptr;
  int len, age;
  Person parr[3];
  for(int i=0; i<3; i++){
    cin >> namestr;
    cin >> age;
    len = strlen(namestr) + 1;
    nameptr = new char[len];
    strcpy(nameptr, namestr);
    parr[i].SetPersonInfo(nameptr, age);
  }

  for(int i=0; i<3; i++)
    parr[i].ShowPersonInfo();

  return 0;
}
