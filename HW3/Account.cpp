#include <iostream>
#include <string>
#include "Account.h"
#include "Transaction.h"

using namespace std;

int Account::call_counter=0;

Account::Account(int amount_init, const int ID_init, const char *owner_init)
{
    std::cout<<"Account\t(ID:"<<ID_init<<")\tconstructed"<<std::endl;
    this->amount=amount_init;
    this->ID=ID_init;
    this->owner.assign(owner_init);

    for(int i;i<100;i++) trans[i]=NULL;
}

bool Account::withdraw(int deductAmount)
{
    if(deductAmount>amount) return false;

    amount-=deductAmount;

    trans[call_counter++] = new Transaction(this,"Withdraw", deductAmount);

    return true;
}


bool Account::deposit(int addAmount)
{
    amount+=addAmount;
    return true;
}

bool Account::transferMoney(Account & AccountOfB, int amountToTransfer)
{
    if(amountToTransfer>amount) return false;

    AccountOfB.deposit(amountToTransfer);
    amount-=amountToTransfer;
    return true;
}

int Account::getAmount()
{
    return amount;
}

string &Account::getOwnerName()
{
    return owner;
}