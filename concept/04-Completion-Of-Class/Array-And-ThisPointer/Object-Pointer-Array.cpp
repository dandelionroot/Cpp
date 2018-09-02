/*
1. Person Class는 Object-Array.cpp과 동일하다.
2. 저장의 대상을 객체 자체로 하느냐, 객체의 주소 값으로 하느냐를 잘 결정 해야한다.
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
	Person *cparr[3];
	char namestr[100];
	int age;

	for(int i=0; i<3; i++) {
		cout << "이름 : " << endl;
		cin >> namestr;
		cout << "나이 : " << endl;
		cin >> age;
		cparr[i] = new Person(namestr, age); // 생성자가 알아서 namestr을 복사한 변수를 할당해줌
	}

	for(int i=0; i<3; i++) {
		cparr[i]->ShowPersonInfo();
	}
	
	for(int i=0; i<3; i++) {
		delete cparr[i]; // new로 생성한 객체는 수동으로 삭제해주어야 한다.
	}
}
