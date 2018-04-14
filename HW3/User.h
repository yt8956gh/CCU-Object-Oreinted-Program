#ifndef USER_H 
#define USER_H

#include <string>
#include <iostream>
#include "Account.h"

class User 
{

friend class Account;

private:

    static int ID_counter;
    int trans_call_counter;
    int ID;
    std::string name;
    std::vector<Transaction*> trans;
    Account account;


public:

    User(const char *name);
    ~User();
    
    const char *getUsername();

    Account &getAccount();

    int getID();

    bool getTrans();

};


#endif