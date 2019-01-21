/*
    * File Name : HighCreditAccount.cpp
    * Version : 0.7
    * Update Date : 2019.01.21
*/

#include <BankingCommonDecl.h>
#include <HighCreditAccount.h>

HighCreditAccount::HighCreditAccount(const int address,
    const char *name, const double balance, const double intRatio,
    const char grade) : NormalAccount(address, name, balance, intRatio),
    grade(grade) {}

HighCreditAccount::HighCreditAccount(const HighCreditAccount &copy)
    : NormalAccount(copy), grade(copy.grade) {}

const bool HighCreditAccount::addBalance(const double balance) {
    double plusRatio = 0;
    bool succeed = false;

    succeed = NormalAccount::addBalance(balance);

    if(balance > 0) {
        switch(this->grade) {
            case 'A':
                plusRatio = 7.0;
                break;
            case 'B':
                plusRatio = 4.0;
                break;
            case 'C':
                plusRatio = 2.0;
                break;
            default:
                break;
        }
        Account::addBalance(balance * plusRatio / 100.0);
    }

    return succeed;
}

void HighCreditAccount::showInfo() const {
    NormalAccount::showInfo();
    cout << "고객등급 : " << this->grade << endl;
}
