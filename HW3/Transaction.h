#include<iostream>
#include<string>
#include "Account.h"


class Trasaction
{
private:
    std::string type[20];
    Account &account;
    int amount;

public:
    Trasaction(const char *,int);
    Trasaction(Account &,const char *,int);

    void print();
};