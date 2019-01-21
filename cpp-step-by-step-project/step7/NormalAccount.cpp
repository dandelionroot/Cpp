/*
    * File Name : NormalAccount.cpp
    * Version : 0.7
    * Update Date : 2019.01.21
*/

#include <BankingCommonDecl.h>
#include <NormalAccount.h>

NormalAccount::NormalAccount(const int address,
    const char *name, const double balance,
    const double intRatio) : Account(address, name, balance),
    intRatio(intRatio) {}

NormalAccount::NormalAccount(const NormalAccount &copy)
    : Account(copy), intRatio(copy.intRatio) {}

const bool NormalAccount::addBalance(const double balance) {
    bool succeed = false;
    succeed = Account::addBalance(balance);

    if(balance > 0)
        Account::addBalance(balance * this->intRatio / 100.0);
    
    return succeed;
}

void NormalAccount::showInfo() const {
    Account::showInfo();
    cout << "이자율 : " << this->intRatio << endl;
}
