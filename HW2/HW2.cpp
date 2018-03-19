#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Word
{
    int count;
    int where;
    string word;
    struct Word *next;
};

typedef struct Word WORD;

int main(void)
{
    int i=0;

    string tmp, filename, tok[3];
    stringstream ss;

    WORD *list[1000];
    size_t string_ptr=0;

    for(i=0;i<1000;i++) list[i]=NULL;

    fstream file;

    while(1)
    {
        cout<<">";

        getline(cin, tmp);

        if(tmp=="end")
        {
            break;
        }
        else if(tmp=="new")
        {
            for(i=0;i<1000;i++)
            {
                list[i]=NULL;
            }
            continue;
        }
        else if(tmp.substr(0,7)=="locate ")//substr(position of substring ,length of substring)
        {
            tmp = tmp.substr(7);
            ss<<tmp;
            ss>>tok[0]>>tok[1]>>tok[2];

            if(tok[0]=="" || tok[1]=="" || tok[2]!="") 
                cout<<"ERROR: Invalid command !"<<endl;

        }
        else if(tmp.substr(0,5)=="load ")
        {
            tmp = tmp.substr(5);

            ss<<tmp;
            ss>>tok[0]>>tok[1];

            if(tok[0]=="" || tok[1]!="")
                cout<<"ERROR: Invalid command !"<<endl;
        }
        else
        {
            cout<<"ERROR: Invalid command !"<<endl;
        }

        for(i=0;i<3;i++) tok[i].clear();
        ss.clear();
        cout.flush();

    }


    return 0;
}