/*
1. 소멸자는 생성자와 같이 반환형이 없다.
2. 소멸자의 매개변수는 void형이다. 따라서 오버로딩도, 디폴트값 설정도 불가능하다.
3. 소멸자는 ~를 앞에 붙인다.
4. 소멸자는 생성자에서 할당한 리소스의 소멸에 자동으로 사용된다.
5. 소멸자를 정의해 두지 않으면 디폴트 생성자처럼 아무일도 하지않는 디폴트 소멸자가 삽입된다.
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
  Person(char *myname, int myage) {
    int len = strlen(myname) + 1;
    name = new char[len];
    strcpy(name, myname);
    age = myage;
  }
  void ShowPersonInfo() const {
    cout << "이름 : " << name << endl;
    cout << "나이 : " << age << endl;
  }
  ~Person() {
    delete []name;
    cout << "distructor is called !" << endl;
  }
};

int main() {
  Person man1("Kim Chang Min", 25);
  Person man2("Kang Min Ha", 27);
  man1.ShowPersonInfo();
  man2.ShowPersonInfo();

  return 0;
}
