#include <iostream>
#include "Transaction.h"

using namespace std;

Transaction::Transaction(const char *type,int amount)
{
    cout<<"Transaction\t(type:"<<type<<")\tconstructed"<<endl;
    this->type.assign(type);
    this_.amount=amount;
}

Transaction::Transaction(Account &account_init,const char *type,int amount):account(account_init)
{
    cout<<"Transaction\t(type:"<<type<<")\tconstructed"<<endl;
    this->type.assign(type);
    this_.amount=amount;
}

void Transaction::print()
{
    if(amount==0) cout<<"Type: "<<type<<endl;

    else cout<<"Type: "<<type<<" "<<amount<<endl;
}