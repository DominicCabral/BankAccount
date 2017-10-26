//
//  main.cpp
//  HW8
//
//  Created by Dominic Cabral on 11/27/14.
//  Copyright (c) 2014 Umass Lowell. All rights reserved.
//

#include <iostream>
#include "BankAccount.h"
#include <string>
using namespace std;

int main()
{
    //init 3 different account types
    BankAccount ba1("Fredric Chopin", 87.24);
    MoneyMarketAccount mma1("William Cosby", 7584.23);
    CDAccount cda1("Cristiano Ronaldo", 25000.00);

    //state info all 3
    cout<<ba1<<endl;
    cout<<mma1<<endl;
    cout<<cda1<<endl;

    //test all methods on BankAccount
    cout<<"Depositing 200..."<<endl;
    ba1.deposit(200.00);
    cout<<ba1<<endl;
    
    cout<<"Withdrawing 80.12..."<<endl;
    ba1.withdraw(80.12);
    cout<<ba1<<endl;

    cout<<"Withdrawing 210 (more than what is in the account)..."<<endl;
    ba1.withdraw(210);
    cout<<ba1<<endl;
    
    //test all methods on MoneyMarketAccount
    cout<<"Depositing 1000..."<<endl;
    mma1.deposit(1000);
    cout<<mma1<<endl;    

    cout<<"Withdrawing 584.23..."<<endl;
    mma1.withdraw(584.23);
    cout<<mma1<<endl;    
    
    cout<<"Withdrawing 1000 (will remove 1000+1.50 because second withdraw)"<<endl;
    mma1.withdraw(1000);
    cout<<mma1<<endl;
    
    //test all methods on CDAccount
    cout<<"Depositing 1000..."<<endl;
    cda1.deposit(1000);
    cout<<cda1<<endl;

    cout<<"Applying Interest..."<<endl;
    cda1.applyinterest();
    cout<<cda1<<endl;

    cout<<"Withdrawing 1000 + 25% of interest applied..."<<endl;
    cda1.withdraw(1000);
    cout<<cda1<<endl;
    
    //Transfer method
    cout << "Transfering 10 from " << cda1.getName() << " to " << mma1.getName() << "..." << endl;
    cda1.transfer(10, mma1);
    cout << cda1 << endl;
    cout << mma1 << endl;

    cout << "Transfering 30000 from " << mma1.getName() << " to " << cda1.getName() << " (Should Fail)..."<< endl;
    cda1.transfer(30000, mma1);
    cout << cda1 << endl;
    cout << mma1 << endl;

    return 0;
}
