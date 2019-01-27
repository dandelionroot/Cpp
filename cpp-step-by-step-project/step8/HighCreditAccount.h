/*
    * File Name : HighCreditAccount.h
    * Version : 0.7
    * Update Date : 2019.01.21
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include <NormalAccount.h>

class HighCreditAccount : public NormalAccount
{
private:
    char grade;
public:
    HighCreditAccount(const int address, const char *name,
        const double balance, const double intRatio,
        const char grade);
    HighCreditAccount(const HighCreditAccount &copy);
    virtual const bool addBalance(const double balance);
    virtual void showInfo() const;
    ~HighCreditAccount();
};

#endif
