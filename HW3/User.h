#include <string>
#include <iostream>
#include "Account.h"

class User 
{

private:

    static int ID_counter;
    static int trans_call_counter;
    int ID;
    std::string name;
    Account account;
    //Transaction *trans[100];

public:

    User(const char *name);
    
    const char *getUsername();

    Account &getAccount();

    int getID();

    //std::string &getTrans();
};


