#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

using namespace std;

int main(void)
{
    int i=0,c=0,count=0;

    string tmp, filename, tok[3], word;
    stringstream ss;
    vector<string> list;
    vector<string>::iterator ptr;
    vector<int> found;

    ifstream file;

    while(1)
    {

        for(i=0;i<3;i++) tok[i].clear();
        ss.clear();
        cout.flush();

        cout<<">";
        getline(cin, tmp);

        if(tmp=="end")
        {
            break;
        }
        else if(tmp=="new")
        {
            list.clear();
            file.close();
            continue;
        }
        else if(tmp.substr(0,7)=="locate ")//substr(position of substring ,length of substring)
        {
            found.clear();
            tmp = tmp.substr(7);
            ss<<tmp;
            ss>>tok[0]>>tok[1]>>tok[2];

            if(tok[0]=="" || tok[1]=="" || tok[2]!="") 
            {
                cout<<"ERROR: Invalid command !"<<endl;
                continue;
            }

            ss.clear();

            ss<<tok[1];

            if(!(ss>>count)||count<=0)// check which all of character in string are number. 
            {
                cout<<"ERROR: Invalid command !"<<endl;
                continue;
            }

            for(i=0;i<list.size(); i++)
            {
                if(list.at(i)==tok[0])
                {
                    found.push_back(i+1);
                }
            }

            try
            {
                if(found.at(count-1))
                    cout<<found.at(count-1)<<endl;
            }
            catch(const std::out_of_range& e)
            {
                cout<<"No matching entry"<<endl;
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
                for(string::iterator ptr=tmp.begin(); ptr<tmp.end(); ptr++)
                {
                    c=*ptr;
                    if(c=='\'') *ptr='\'';
                    else if(!isalpha(c)) *ptr=' ';
                }

                //cout<<tmp<<endl;
                ss.clear();
                ss<<tmp;

                while(ss>>word)
                {
                    list.push_back(word);
                }
            }
        }
        else
        {
            cout<<"ERROR: Invalid command !"<<endl;
        }
    }

    return 0;
}
