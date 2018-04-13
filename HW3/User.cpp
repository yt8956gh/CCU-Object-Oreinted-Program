#include "User.h"

using namespace std;


int User::ID_counter=0;//static variable initialization should be in .cpp



//  Must initializing account(other class) in member initializers list,
//  or the constructor will initialize account instance too late,
//  which lead to throw a compile error.

User::User(const char *name):account(0,ID_counter,name)
{
    std::cout<<"User\t(ID:"<<ID_counter<<")\tconstructed"<<endl<<endl;
    this->name.assign(name);
    this->ID=ID_counter++;

    trans=NULL;
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

string& User::getTrans()
{

}