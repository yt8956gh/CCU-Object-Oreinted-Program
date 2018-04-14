#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Account.h"

using namespace std;

Account::Account(int amount_init, const int ID_init, const char *owner_init, User* user)
{
    cout<<"Account\t(ID:"<<ID_init<<")\tconstructed"<<endl;
    this->amount=amount_init;
    this->ID=ID_init;
    this->owner.assign(owner_init);
    this->user=user;
    this->trans_counter=0;
    user->trans.push_back(Transaction(this,"Create", 0));
}


Account::~Account()
{
    cout<<"Account\t(ID:"<<ID<<")\tdestructed"<<endl;
}

bool Account::withdraw(int deductAmount)
{
    if(deductAmount>amount) return false;

    amount-=deductAmount;

    user->trans.push_back(Transaction(this,"Withdraw", deductAmount));
    trans_counter++;

    return true;
}


bool Account::deposit(int addAmount)
{
    amount+=addAmount;

    user->trans.push_back(Transaction(this,"Deposit", addAmount));
    trans_counter++;

    return true;
}

bool Account::transferMoney(Account & AccountOfB, int amountToTransfer)
{
    if(amountToTransfer>amount) return false;

    user->trans.push_back(Transaction(&AccountOfB,"Transfer", amountToTransfer));
    trans_counter++;

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
