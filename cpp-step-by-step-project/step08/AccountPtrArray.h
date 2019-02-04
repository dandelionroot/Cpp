/*
    * File Name : AccountPtrArray.h
    * Version : 0.1
    * Update Date : 2019.01.27
*/

#ifndef __ACCOUNT_PTR_ARRAY_H__
#define __ACCOUNT_PTR_ARRAY_H__

#include <Account.h>
typedef Account* ACCOUNT_PTR;

// Account 포인터 배열 클래스
class AccountPtrArray
{
private:
    ACCOUNT_PTR* arr;
    int arrlen;
    // 복사 생성자 접근금지
    AccountPtrArray(const AccountPtrArray& copy);
    // 대입 연산자 접근금지
    AccountPtrArray& operator= (const AccountPtrArray& copy);
public:
    AccountPtrArray(int arrlen = 100);
    // 수정용 index 연산자 오버로딩
    ACCOUNT_PTR& operator[] (int index);
    // 조회용 index 연산자 오버로딩
    ACCOUNT_PTR operator[] (int index) const;
    int length() const;
    ~AccountPtrArray();
};

#endif
