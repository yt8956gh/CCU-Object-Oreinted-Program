#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main(void)
{
    int i=0,c=0;

    string tmp, filename, tok[3], word;
    stringstream ss;
    vector<string> list;
    vector<string>::iterator k;

    ifstream file;

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
            continue;
        }
        else if(tmp.substr(0,7)=="locate ")//substr(position of substring ,length of substring)
        {
            tmp = tmp.substr(7);
            ss<<tmp;
            ss>>tok[0]>>tok[1]>>tok[2];

            if(tok[0]=="" || tok[1]=="" || tok[2]!="") 
            {
                cout<<"ERROR: Invalid command !"<<endl;
                continue;
            }


        }
        else if(tmp.substr(0,5)=="load ")
        {
            tmp = tmp.substr(5);
            ss<<tmp;
            ss>>tok[0]>>tok[1];

            if(tok[0]=="" || tok[1]!="")
            {
                cout<<"ERROR: Invalid command !"<<endl;
                continue;
            }

            filename = tok[0];

            file.open(filename.c_str(), ios::in);

            if(!file)
            {
                cout<<"Fail to open file!"<<endl;
                continue;
            }

            while(getline(file, tmp))
            {
                for(string::iterator k=tmp.begin(); k<tmp.end(); k++)
                {
                    c=*k;
                    if(c<'A'||(c>'Z'&&c<'a')||c>'z') *k=' ';
                }

                cout<<tmp<<endl;

                ss.clear();
                ss<<tmp;

                while(ss>>word)
                {
                    list.push_back(word);
                }
            }

            for(i=0;i<list.size(); i++)
            {
                cout<<list.at(i)<<endl;
            }

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