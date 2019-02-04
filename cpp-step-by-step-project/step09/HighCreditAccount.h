/*
    * File Name : HighCreditAccount.h
    * Version : 0.8
    * Update Date : 2019. 02. 04.
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include <NormalAccount.h>

class HighCreditAccount : public NormalAccount
{
private:
    char grade;
public:
    HighCreditAccount(const int address, const String name,
        const double balance, const double intRatio,
        const char grade);
    HighCreditAccount(const HighCreditAccount &copy);
    virtual const bool addBalance(const double balance);
    virtual void showInfo() const;
    ~HighCreditAccount();
};

#endif
