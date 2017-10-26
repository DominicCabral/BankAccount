//
//  BankAccount.cpp
//  HW8
//
//  Created by Dominic Cabral on 11/27/14.
//  Copyright (c) 2014 Umass Lowell. All rights reserved.
//

#include "BankAccount.h"

BankAccount::BankAccount()
{   name = "";
    balance = 0.00;
};

BankAccount::BankAccount(string accountname, float startingamount)
{
    name = accountname;
    balance = startingamount;
};

string BankAccount::getName() const
{
    return name;
}

double BankAccount::getBalance() const
{
    return balance;
}

void BankAccount::deposit(float amount)
{
    balance+=amount;
}

double BankAccount::withdraw(float amount)
{
    if (amount>balance)
    {
        cout << "insufficient funds for the withdrawal to take place" <<endl;
        return 1;
    }
    else
    {
        balance-=amount;
        cout << "ok" << endl;
        return 0;
    }
}

void BankAccount::transfer(float amount, BankAccount &ToAccount)
{
    if(withdraw(amount)==0)
    {
        ToAccount.deposit(amount);
    }
    else
    {
        cout << "transfer could not occur" << endl;
    }
    
}

ostream& operator<<(ostream& os, const BankAccount& account)
{
    cout<<"Name: "<< account.name << " " << "Balance: " << account.balance << endl;
    return os;
};

MoneyMarketAccount::MoneyMarketAccount()
{
    name = "";
    balance = 0.00;
    numberOfWithdrawls = 0;
}

MoneyMarketAccount::MoneyMarketAccount(string accountname, float amount)
{
    name = accountname;
    balance = amount;
    numberOfWithdrawls = 0;
}

double MoneyMarketAccount::withdraw(float amount)
{
    if (numberOfWithdrawls>=1)
    {   numberOfWithdrawls+=1;
        if((BankAccount::withdraw(amount+1.50))==1)
        {return 1;}
        else
            return 0;
    }
    else
    {   numberOfWithdrawls+=1;
        if((BankAccount::withdraw(amount))==1)
        {return 1;}
        else
            return 0;
    }
}

CDAccount::CDAccount()
{
    name = "";
    balance = 0.00;
    interestRate = .03125;
    interestAdded = 0;
}

CDAccount::CDAccount(string accountname,float amount)
{
    name = accountname;
    balance = amount;
    interestRate = .03125;
    interestAdded = 0;
}

void CDAccount::applyinterest()
{
    interestAdded+= balance*interestRate;
    balance+= balance*interestRate;
}

double CDAccount::withdraw(float amount)
{
    double penalty;
    
    penalty = interestAdded*.25;
    
    if(BankAccount::withdraw(amount+penalty)==1)
    {return 1;}
    else
    {return 0;}
}



