/*
    * File Name : AccountPtrArray.cpp
    * Version : 0.1
    * Update Date : 2019.01.27
*/

#include <AccountPtrArray.h>
#include <BankingCommonDecl.h>

AccountPtrArray::AccountPtrArray(const AccountPtrArray& copy) {}

AccountPtrArray& AccountPtrArray::operator= (const AccountPtrArray& copy) {}

AccountPtrArray::AccountPtrArray(int arrlen) : arrlen(arrlen) {
    this->arr = new ACCOUNT_PTR[arrlen];
}

ACCOUNT_PTR& AccountPtrArray::operator[] (int index) {
    if(index < 0 || index >= arrlen) {
        cout << "index out of range" << endl;
        exit(1);
    }
    return arr[index];
}
ACCOUNT_PTR AccountPtrArray::operator[] (int index) const {
    if(index < 0 || index >= arrlen) {
        cout << "index out of range" << endl;
        exit(1);
    }
    return arr[index];
}
int AccountPtrArray::length() const {
    return this->arrlen;
}
AccountPtrArray::~AccountPtrArray() {
    delete []this->arr;
}
