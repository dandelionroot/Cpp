/*
    * File Name : AccountException.h
    * Version : 0.1
    * Update Date : 2019. 02. 04.
*/

#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

#include <iostream>
using namespace std;

class AccountException
{
public:
	// 세부사항은 Derived Class에서 정의, 순수 가상함수
	virtual void showException() const = 0;
};

class OverWithdraw : public AccountException
{
private:
	double moneyLeft;
public:
	OverWithdraw(double moneyLeft) : moneyLeft(moneyLeft) {}
	virtual void showException() const {
		cout << "잔액 부족 ! 현재 잔액 : " <<
			this->moneyLeft << endl;
		cout << "다시 시도하세요." << endl;
	}
};

class MinusMoney : public AccountException
{
public:
	virtual void showException() const {
		cout << "음의 값을 입력할 수 없습니다." << endl;
		cout << "다시 시도하세요." << endl;
	}
};

#endif
