/*
    * File Name : NormalAccount.h
    * Version : 0.7
    * Update Date : 2019.01.21
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include <Account.h>

class NormalAccount : public Account
{
private:
    double intRatio;
public:
    NormalAccount(const int address, const char *name,
        const double balance, const double intRatio);
    NormalAccount(const NormalAccount &copy);
    virtual const bool addBalance(const double balance);
    virtual void showInfo() const;
    ~NormalAccount();
};

#endif
