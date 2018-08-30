/*
1. 객체 생성과정에서 생성자를 사용하는 방법 2가지
  1> 전역, 지역 및 매개변수의 형태
    SimpleClass sc(20);
  2> 동적 할당의 형태
    SimpleClass *ptr = new SimpleClass(20);
2. 생성자도 함수의 일종이니 오버로딩이 가능하며, 매개변수에 디폴트 값을 설정할 수 있다.
3. 하지만, 생성자로 객체를 생성할 때 매개변수를 넘기지 않는 경우, 괄호를 쓰면 안된다.
4. 그 이유를 말하자면, 함수의 원형선언(정의 말고)은 함수내에 지역적으로도 가능하기 때문에, 함수의 원형선언인지 생성자인지 구분하기 어렵기 때문이다.
*/

#include <iostream>
using namespace std;

class FruitSeller
{
private:
  int APPLE_PRICE;
  int numOfApples;
  int myMoney;
public:
  FruitSeller(int price, int num, int money) // 생성자
    : APPLE_PRICE(price), numOfApples(num), myMoney(money) // 멤버 이니셜라이저를 이용한 객체가 아닌 멤버의 초기화
  {}
  int SaleApples(int money)
  {
    int num = money / APPLE_PRICE;
    numOfApples -= num;
    myMoney += money;
    return num;
  }
  void ShowSalesResult() const
  {
    cout << "남은 사과 : " << numOfApples << endl;
    cout << "판매 수익 : " << myMoney << endl << endl;
  }
};

class FruitBuyer
{
private:
  int myMoney;
  int numOfApples;
public:
  FruitBuyer(int money) // 생성자
    : myMoney(money), numOfApples(0) // 멤버 이니셜라이저를 이용한 객체가 아닌 멤버의 초기화
  {}
  void BuyApples(FruitSeller &seller, int money)
  {
    numOfApples += seller.SaleApples(money);
    myMoney -= money;
  }
  void ShowBuyResult() const
  {
    cout << "현재 잔액 : " << myMoney << endl;
    cout << "사과 개수 : " << numOfApples << endl << endl;
  }
};

int main(int argc, char const *argv[]) {
  FruitSeller seller(1000, 20, 0);
  FruitBuyer buyer(5000);
  buyer.BuyApples(seller, 2000);

  cout << "과일 판매자의 현황" << endl;
  seller.ShowSalesResult();
  cout << "과일 구매자의 현황" << endl;
  buyer.ShowBuyResult();
  return 0;
}
