#ifndef TRANSACTION_H 
#define TRANSACTION_H

#include<iostream>
#include<string>

class Account;//for include with Account.h each other

class Transaction
{
private:
    std::string type;
    Account *account;
    int amount,transfer_switch;

public:
    Transaction(Account *,const char *,int);

    ~Transaction();

    void print();
};

#endif