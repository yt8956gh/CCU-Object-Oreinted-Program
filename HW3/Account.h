#ifndef ACCOUNT_H 
#define ACCOUNT_H

#include "Transaction.h"
#include <string>
#include <vector>

class User;

class Account
{

    private:
        int trans_counter;
        int ID;
        int amount;
        User* user;
        std::string owner;
        

    public:
        //Member initialization list

        Account(int,const int, const char *, User*);

        bool withdraw(int);

        bool deposit(int);

        bool transferMoney(Account &, int);

        int getAmount();

        std::string &getOwnerName();


};

#endif