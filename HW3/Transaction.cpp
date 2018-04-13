#include <iostream>
#include "Transaction.h"
#include "Account.h"

using namespace std;

Transaction::Transaction(Account *account_init,const char *type,int amount)
{

    this->account = account_init;
    this->type.assign(type);

    if(this->type==string("Transferred"))
    {
        cout<<"Transaction\t(type:Transfer)\tconstructed"<<endl;
        transfer_switch=1;
    }
    else
    {
        cout<<"Transaction\t(type:"<<type<<")\tconstructed"<<endl;
        transfer_switch=0;
    }

    this->amount=amount;
}

void Transaction::print()
{
    if(transfer_switch==1) cout<<"Type: Transferred "<<amount<<" to "<<account->getOwnerName()<<endl;

    else cout<<"Type: "<<type<<" "<<amount<<endl;
}