#include<iostream>
#include <stdlib.h>
#include <time.h>
#include "User.h"

using namespace std;

int main(void)
{
    srand( time(NULL) );
    int x = rand();


    User A("Pooh"),B("Piget"),C("Tigger");

    Account a=A.getAccount();
    Account b=B.getAccount();
    Account c=C.getAccount();

    cout<<endl<<"--------------User list--------------"<<endl<<endl;
    cout<<"A's name: "<<a.getOwnerName()<<endl;
    cout<<"A's Amount: "<<a.getAmount()<<endl;
    cout<<"A's ID: "<<A.getID()<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"B's name: "<<b.getOwnerName()<<endl;
    cout<<"B's Amount: "<<b.getAmount()<<endl;
    cout<<"B's ID: "<<B.getID()<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"A's name: "<<c.getOwnerName()<<endl;
    cout<<"A's Amount: "<<c.getAmount()<<endl;
    cout<<"A's ID: "<<C.getID()<<endl;



    cout<<"----------Transaction start----------"<<endl<<endl;


    for(int i=0;i<100;i++)
    {
        switch(i%9)
        {
            case 0:
                if(a.deposit((rand()%10)*100)) cout<<"Deposit successfully"<<endl;
                else cout<<"Fail to deposit"<<endl;
                break;

            case 1:
                if(b.deposit((rand()%10)*100)) cout<<"Deposit successfully"<<endl;
                else cout<<"Fail to deposit"<<endl;
                break;

            case 2:
                if(c.deposit((rand()%10)*100)) cout<<"Deposit successfully"<<endl;
                else cout<<"Fail to deposit"<<endl;
                break;


            case 3:
                if(a.withdraw((rand()%10)*100)) cout<<"Withdraw successfully"<<endl;
                else cout<<"Fail to withdraw"<<endl;
                break;

            case 4:
                if(b.withdraw((rand()%10)*100)) cout<<"Withdraw successfully"<<endl;
                else cout<<"Fail to withdraw"<<endl;
                break;

            case 5:
                if(c.withdraw((rand()%10)*100)) cout<<"Withdraw successfully"<<endl;
                else cout<<"Fail to withdraw"<<endl;
                break;

            case 6:
                if(a.transferMoney(b,(rand()%10)*100)) cout<<"TransferMoney successfully"<<endl;
                else cout<<"Fail to transferMoney"<<endl;
                if(a.transferMoney(c,(rand()%10)*100)) cout<<"TransferMoney successfully"<<endl;
                else cout<<"Fail to transferMoney"<<endl;
                break;

            case 7:
                if(b.transferMoney(c,(rand()%10)*100)) cout<<"TransferMoney successfully"<<endl;
                else cout<<"Fail to transferMoney"<<endl;
                if(b.transferMoney(a,(rand()%10)*100)) cout<<"TransferMoney successfully"<<endl;
                else cout<<"Fail to transferMoney"<<endl;
                break;

            case 8:
                if(c.transferMoney(a,(rand()%10)*100)) cout<<"TransferMoney successfully"<<endl;
                else cout<<"Fail to transferMoney"<<endl;
                if(c.transferMoney(b,(rand()%10)*100)) cout<<"TransferMoney successfully"<<endl;
                else cout<<"Fail to transferMoney"<<endl;
                break;

        }
    }

    cout<<endl<<"----------Transaction print----------"<<endl<<endl;

    cout<<endl<<a.getOwnerName()<<endl<<endl;
    while(A.getTrans()){}

    cout<<endl<<b.getOwnerName()<<endl<<endl;
    while(B.getTrans()){}


    cout<<endl<<c.getOwnerName()<<endl<<endl;
    while(C.getTrans()){}


    cout<<endl<<"------------Final Result-------------"<<endl<<endl;
    cout<<"A's name: "<<a.getOwnerName()<<endl;
    cout<<"A's Amount: "<<a.getAmount()<<endl;
    cout<<"A's ID: "<<A.getID()<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"B's name: "<<b.getOwnerName()<<endl;
    cout<<"B's Amount: "<<b.getAmount()<<endl;
    cout<<"B's ID: "<<B.getID()<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"A's name: "<<c.getOwnerName()<<endl;
    cout<<"A's Amount: "<<c.getAmount()<<endl;
    cout<<"A's ID: "<<C.getID()<<endl;
    cout<<"-------------------------------------"<<endl;

    return 0;
}
