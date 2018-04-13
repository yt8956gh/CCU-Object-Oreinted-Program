#ifndef ACCOUNT_H 
#define ACCOUNT_H

#include "Transaction.h"
#include <string>

class Account
{
    private:
        static int call_counter;
        int ID;
        int amount;
        std::string owner;
        Transaction *trans[100];

    public:
        //Member initialization list
        Account(int,const int, const char *);

        bool withdraw(int);

        bool deposit(int);

        bool transferMoney(Account &, int);

        int getAmount();

        std::string &getOwnerName();
};

#endif