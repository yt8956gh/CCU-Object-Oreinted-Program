#include <iostream>
#include "Transaction.h"
#include "Account.h"

using namespace std;

Transaction::Transaction(Account *account_init,const char *type,int amount)
{

    cout<<"Transaction\t(type:"<<type<<")\tconstructed"<<endl;


    this->account = account_init;
    this->type.assign(type);


    //transfer_switch is a variable used to check weither the type is transfer in print()  
    if(this->type==string())    transfer_switch=1;
    else    transfer_switch=0;


    this->amount=amount;

}

Transaction::~Transaction()
{
    cout<<"Transaction\t(type:"<<type<<")\tdestructed"<<endl;
}



void Transaction::print()
{
    if(type==string("Transfer")) cout<<"Type: Transferred "<<amount<<" to "<<account->getOwnerName()<<endl;

    else if (type==string("Create")) cout<<"Type: "<<type<<endl;

    else cout<<"Type: "<<account->getOwnerName()<<" "<<type<<" "<<amount<<endl;
}