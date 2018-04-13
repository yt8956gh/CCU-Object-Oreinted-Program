#include "User.h"

using namespace std;


int User::ID_counter=0;//static variable initialization should be in .cpp

//  Must initializing account(other class) in member initializers list,
//  or the constructor will initialize account instance too late,
//  which lead to throw a compile error.

User::User(const char *name):account(0,ID_counter,name,this)
{
    std::cout<<"User\t(ID:"<<ID_counter<<")\tconstructed"<<endl<<endl;
    this->name.assign(name);
    this->ID=ID_counter++;
    this->trans_call_counter=0;
}


const char * User::getUsername()
{
    return name.c_str();
}

Account& User::getAccount()
{
    return account;
}

int User::getID()
{
    return ID;
}

bool User::getTrans()
{
    // size return number of item ,so operator is "<"
    if(trans_call_counter<trans.size())
    {
         trans.at(trans_call_counter).print();
         trans_call_counter++;
         return true;
    }
    else return false;
}