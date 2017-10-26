//
//  BankAccount.h
//  HW8
//
//  Created by Dominic Cabral on 11/27/14.
//  Copyright (c) 2014 Umass Lowell. All rights reserved.
//

#ifndef __HW8__BankAccount__
#define __HW8__BankAccount__

#include <iostream>
#include <string>
using namespace std;


class BankAccount
{
protected:
    string name;
    double balance;
    
public:
    BankAccount();
    BankAccount(string accountname, float amount);
    string getName() const;
    double getBalance() const;
    void deposit(float amount);
    virtual double withdraw(float amount);
    void transfer(float amount, BankAccount &ToAccount);
    friend ostream& operator<<(ostream& os, const BankAccount& account);
};


//Derived Class of BankAccount
class MoneyMarketAccount : public BankAccount
{
protected:
    float numberOfWithdrawls;
public:
    MoneyMarketAccount();
    MoneyMarketAccount(string accountname, float amount);
    double withdraw(float amount);
};


//Another Derived Class of BankAccount
class CDAccount : public BankAccount
{
protected:
    double interestRate;
    double interestAdded;
    
public:
    CDAccount();
    CDAccount(string accountname, float amount);
    void applyinterest();
    double withdraw(float amount);
};

ostream& operator<<(ostream& os, const BankAccount& account);


#endif /* defined(__HW8__BankAccount__) */
