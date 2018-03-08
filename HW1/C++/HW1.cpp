#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char** argv) {
    
    string tmp;
    int i=0,j=0,len=0,isPal=1;
    char tmpr,tmpl;
    
    cout<<"Hint: Key Enter Directly to Exit!\n"<<endl
        <<"Please enter potential palindrome:"<<endl;

    //get line including space form stdin
    getline(cin, tmp);
    len = tmp.size();

    // Can Key Enter without other characters to Exit!
    while(len!=0)
    {        
        i=0; j=len-1; isPal = 1;

        while(i<len || j>=0)
        {
            while(i<len && !isalpha(tmp[i])) i++;
            while(j>=0 && !isalpha(tmp[j])) j--;
            
            // avoid the pointer i & j move over the range of String
            if(i>len || j<0) break;
            
            tmpr=tmp[i]; tmpl=tmp[j];
                                
            if(toupper(tmpr)!=toupper(tmpl))
            {
                    isPal = 0;
                    break;
            }
            
            i++; j--;
        }
        
        if(isPal==1)    cout<<"Yes\n"<<endl;
        else    cout<<"No\n"<<endl;
        
        //get line for next round in while loop
        cout<<"Please enter potential palindrome:"<<endl;
        getline(cin, tmp);
        len = tmp.size();    
    }

    return 0;
}
