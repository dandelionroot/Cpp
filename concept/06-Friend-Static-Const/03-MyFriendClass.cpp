#include <iostream>
#include <cstring>
using namespace std;

class Girl;

class Boy {
private:
	int height;
	friend class Girl;
public:
	Boy(int len) : height(len) {}
	void ShowYourFriendInfo(Girl &frn); // 4행에서 Girl을 선언해주었기 때문에 컴파일 에러가 나지 않음.
};

class Girl {
private:
	char phNum[20];
public:
	Girl(char * num) {
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy &frn);
	friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl &frn) { // girl객체가 phNum멤버를 가지고 있는지 알아야하므로 Girl객체선언 뒤에서 이 함수를 정의한 것이다.
	cout << "Her phone number : " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy &frn) {
	cout << "His height : " << frn.height << endl;
}

int main(void) {
	Boy boy(170);
	Girl girl("010-1234-5678");
	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);
	return 0;
}

/*
1. friend 선언은 public, private 어디서든 가능
2. Girl에서 Boy를 friend선언하면 Boy는 girl의 private 멤버에 접근이 가능
 
*/
