//
//  BankAccount.h
//  HW8
//
//  Created by Dominic Cabral on 11/27/14.
//  Update by Dominic Cabral on 10/25/17
//  Copyright (c) 2014 Umass Lowell. All rights reserved.
//

#ifndef __HW8__BankAccount__
#define __HW8__BankAccount__

#include <iostream>
#include <string>
using namespace std;

// Base class for all types of Bank Accounts
// includes all standard operations for any type of BankAccount
// withdraw gets overridden in each class because each type of BankAccount withdraws differently
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


//BankAccount that simulates a MoneyMarket Account
//The user gets 1 free withdrawal. 
//After the free withdrawal has been used,
//a withdrawal fee of $1.50 is deducted from the balance per withdrawal.
//The class keeps track of the number of withdrawals and overrides the withdraw function.
class MoneyMarketAccount : public BankAccount
{
    protected:
        float numberOfWithdrawls;

    public:
        MoneyMarketAccount();
        MoneyMarketAccount(string accountname, float amount);
        double withdraw(float amount);
};

//BankAccount that simulates a CDAccount
//by adding interest: balance+= interest rate*balance.
//CD accounts incur penalties for the early withdrawal of funds.
//A withdrawal of any amount incurs a penalty = 25% of an interest rate applied to the balance.
//Assume the amount withdrawn plus the penalty are deducted from the account balance.
//Again the withdraw function must override the one in the base class.
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
