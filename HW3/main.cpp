#include<iostream>
#include "User.h"

using namespace std;

int main(void)
{
    //const string name("Pooh");

    Transaction *transPtr=NULL;
    User A("Pooh"),B("Piget");//const char *

    Account a1=A.getAccount();
    Account b=B.getAccount();


    if(a1.withdraw(1100))
        cout<<"Successfully"<<endl;
    else
        cout<<"Fail to withdraw"<<endl;


    a1.deposit(500);
    b.deposit(1000);
    b.withdraw(1);
    
    if(a1.transferMoney(b,500))
        cout<<"Successfully"<<endl;
    else
        cout<<"Fail to transferMoney"<<endl;


    while(A.getTrans()){}

    while(B.getTrans()){}
    
    cout<<"A's name: "<<a1.getOwnerName()<<endl;
    cout<<"A's Amount: "<<a1.getAmount()<<endl;
    cout<<"A's ID: "<<A.getID()<<endl;

    cout<<"B's name: "<<b.getOwnerName()<<endl;
    cout<<"B's Amount: "<<b.getAmount()<<endl;
    cout<<"B's ID: "<<B.getID()<<endl;

    return 0;
}
