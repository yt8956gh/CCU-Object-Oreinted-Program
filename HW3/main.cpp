#include<iostream>
#include "User.h"

using namespace std;

int main(void)
{
    User A("Pooh"),B("Piget");

    Account a=A.getAccount();
    Account b=B.getAccount();

    cout<<"A's name: "<<a.getOwnerName()<<endl;
    cout<<"A's Amount: "<<a.getAmount()<<endl;
    cout<<"A's ID: "<<A.getID()<<endl<<endl;

    cout<<"B's name: "<<b.getOwnerName()<<endl;
    cout<<"B's Amount: "<<b.getAmount()<<endl;
    cout<<"B's ID: "<<B.getID()<<endl<<endl;





    if(a.withdraw(1100))
        cout<<"Successfully"<<endl;
    else
        cout<<"Fail to withdraw"<<endl;


    a.deposit(500);
    b.deposit(1000);
    b.withdraw(1);
    
    if(a.transferMoney(b,500))
        cout<<"Successfully"<<endl;
    else
        cout<<"Fail to transferMoney"<<endl;


    while(A.getTrans()){}

    while(B.getTrans()){}
    
    cout<<"A's name: "<<a.getOwnerName()<<endl;
    cout<<"A's Amount: "<<a.getAmount()<<endl;
    cout<<"A's ID: "<<A.getID()<<endl;

    cout<<"B's name: "<<b.getOwnerName()<<endl;
    cout<<"B's Amount: "<<b.getAmount()<<endl;
    cout<<"B's ID: "<<B.getID()<<endl;

    return 0;
}
