#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char* str;
    int len;
public:
    // 인자가 없는 생성자
    String() {
        this->len = 0;
        this->str = NULL;
    }

    // 문자열이 인자인 생성자
    String(const char* s) {
        this->len = strlen(s)+1;
        this->str = new char[this->len];
        strcpy(this->str, s);
    }

    // 복사 생성자
    String(const String& copy) {
        this->len = copy.len;
        this->str = new char[this->len];
        strcpy(this->str, copy.str);
    }

    // 소멸자
    ~String() {
        if(this->str != NULL)
            delete []str;
    }

    // 대입 연산자
    String& operator= (const String& s) {
        if(this->str != NULL)
            delete []this->str;
        this->len = s.len;
        this->str = new char[this->len];
        strcpy(this->str, s.str);
        return *this;
    }

    // + 연산자
    String operator+ (const String& s) {
        char* c = new char[this->len+s.len-1];
        strcpy(c, this->str);
        strcat(c, s.str);
        String temp(c);
        delete []c;
        return temp;
    }

    // += 연산자
    String& operator+= (const String& s) {
        this->len += (s.len-1);
        char* c = new char[this->len];
        strcpy(c, this->str);
        strcat(c, s.str);
        if(this->str != NULL)
            delete []this->str;
        this->str = c;
        return *this;
    }

    // == 연산자
    bool operator== (const String& s) {
        return strcmp(this->str, s.str) ? false : true;
    }

    // <<와 >>는 호출 순서상 멤버함수로 오버로딩 할수 없음
    friend ostream& operator<< (ostream& os, String& s);
    friend istream& operator>> (istream& is, String& s);
};

ostream& operator<< (ostream& os, String& s) {
    return os << s.str;
}

istream& operator>> (istream& is, String& s) {
    char str[100];
    is >> str;
    s = String(str);
    return is;
}

int main(void)
{
    // 인자없는 생성자 호출
    String plzinput;

    // 문자열을 전달받는 생성자의 호출
    String mystr1 = "Hello, My name is "; // -> String mystr1("Hello, My name is ");
    String mystr2 = "devsophia."; // -> String mystr2("devsophia.");

    // 오버로딩한 + 및 = 연산자 호출
    String mystr3 = mystr1 + mystr2; // -> String mystr3 = mystr1.operator+(mystr2);
                                     // -> mystr3.operator=(+ 연산자의 반환값);

    // 오버로딩한 >> 연산자 호출
    cin >> plzinput; // -> operator>>(cin, plzinput);

    // 오버로딩한 << 연산자 호출
    cout << plzinput << endl;
    
    cout << mystr1 << endl;
    cout << mystr2 << endl;
    cout << mystr3 << endl;

    // 오버로딩한 += 연산자 호출
    mystr1 += mystr2; // -> mystr1.operator+=(mystr2);

    cout << mystr1 << endl;

    // 오버로딩한 == 연산자 호출
    if(mystr1 == mystr3)
        cout << "same !" << endl;
    else
        cout << "different !" << endl;

    return 0;
}
