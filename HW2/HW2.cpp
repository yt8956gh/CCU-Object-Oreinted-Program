#include <iostream>
#include <string>
#include <fstream>
#include <sstream> //stringstream
#include <vector>
#include <stdexcept> //處理例外

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
        // initialize
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
            ss>>tok[0]>>tok[1]>>tok[2];// Syntax : locate [word] [N: N-st words]

            if(tok[0]=="" || tok[1]=="" || tok[2]!="") 
            {
                cout<<"ERROR: Invalid command !"<<endl;
                continue;
            }

            ss.clear();

            ss<<tok[1];
            // check whether all of character in string are number. 
            if(!(ss>>count)||count<=0)//當ss的buffer內沒有字元或輸出不合法時回傳failbit
            {
                cout<<"ERROR: Invalid command !"<<endl;
                continue;
            }

            for(i=0;i<list.size(); i++)//將出現該word的位置push進vecter<int> found
            {
                if(list.at(i)==tok[0])
                {
                    found.push_back(i+1);//word從1開始計算
                }
            }

            try//當count(locate的第三個變數)大於found的max-index時，拋出out_of_range
            {
                if(found.at(count-1))
                    cout<<found.at(count-1)<<endl;
            }
            catch(const std::out_of_range& e)//catch上述例外
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

            file.open(filename.c_str(), ios::in);//string::open只吃char[]型態的字串

            if(!file)
            {
                cout<<"Fail to open file!"<<endl;
                continue;
            }

            while(getline(file, tmp))
            {
                //iterating every word in a line for checking the chars exclusing alphabets and apostrophe 
                for(string::iterator ptr=tmp.begin(); ptr<tmp.end(); ptr++)
                {
                    c=*ptr;
                    if(c=='\'') *ptr='\'';
                    else if(!isalpha(c)) *ptr=' ';
                }

                //cout<<tmp<<endl;
                ss.clear();
                ss<<tmp;

                while(ss>>word)//當ss的buffer內沒有字元或輸出不合法時回傳failbit
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
