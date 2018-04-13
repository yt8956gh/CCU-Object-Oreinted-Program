#include "Account.h"
#include <iostream>


Account::Account(int amount_init, const int ID_init)
{
    std::cout<<"Account\t(ID:"<<ID_init<<")\tconstructed"<<std::endl;
    this->amount=amount_init;
    this->ID=ID_init;
}

bool Account::withdraw(int deductAmount)
{
    if(deductAmount>amount) return false;

    amount-=deductAmount;
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