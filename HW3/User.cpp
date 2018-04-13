#include "User.h"
#include <string>

using namespace std;


int User::ID_counter=0;//static variable initialization should be in .cpp



//  Must initializing account(other class) in member initializers list,
//  or the constructor will initialize account instance too late,
//  which lead to throw a compile error.

User::User(const char *name):account(0,ID_counter)
{
    std::cout<<"User\t(ID:"<<ID_counter<<")\tconstructed"<<endl<<endl;
    this->name.assign(name);
    this->ID=ID_counter++;

    //for(int i=0;i<100;i++) trans[i]=NULL;
    //trans[0] = Transaction("Create",0);
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

//string& User::getTrans()
//{

//}