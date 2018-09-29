#include <iostream>
using namespace std;

class Point; // 11, 12행을 위한 선언

class PointOP {
private:
	int opcnt;
public:
	PointOP() : opcnt(0) {}
	Point PointAdd(const Point&, const Point&);
	Point PointSub(const Point&, const Point&);
	~PointOP() {
		cout << "Operation times: " << opcnt << endl;
	}
};

class Point {
private:
	int x;
	int y;
public:
	Point(const int &xpos, const int &ypos) : x(xpos), y(ypos) {}
	friend Point PointOP::PointAdd(const Point&, const Point&);
	friend Point PointOP::PointSub(const Point&, const Point&);
	friend void ShowPointPos(const Point&);
};

Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2) {
	opcnt++;
	return Point(pnt1.x+pnt2.x, pnt1.y+pnt2.y); // 24행에 의해 Point의 private멤버에 접근이 가능
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2) {
	opcnt++;
	return Point(pnt1.x-pnt2.x, pnt1.y-pnt2.y); // 25행에 의해 가능
}

int main(void) {
	Point pos1(1, 2);
	Point pos2(2, 4);
	PointOP op;

	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos1, pos2));
	return 0;
}

void ShowPointPos(const Point& pos) { // 멤버함수가 아닌 일반 함수
	cout << "x : " << pos.x << ", "; // 26행에 의해 가능
	cout << "y : " << pos.y << endl;
}

/*
생성자를 통한 반환, 임시객체의 생성에 주목..
*/
