/*
    * File Name : NormalAccount.h
    * Version : 0.8
    * Update Date : 2019. 02. 04.
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include <Account.h>

class NormalAccount : public Account
{
private:
    double intRatio;
public:
    NormalAccount(const int address, const String name,
        const double balance, const double intRatio);
    NormalAccount(const NormalAccount &copy);
    virtual const bool addBalance(const double balance);
    virtual void showInfo() const;
    ~NormalAccount();
};

#endif
