#ifndef TRANSACTION_H 
#define TRANSACTION_H

#include<iostream>
#include<string>

class Account;

class Transaction
{
private:
    std::string type;
    Account *account;
    int amount,transfer_switch;

public:
    Transaction(Account *,const char *,int);

    void print();
};

#endif