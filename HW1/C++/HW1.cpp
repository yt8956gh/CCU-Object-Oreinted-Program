#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char** argv) {
	
	string tmp;
	int i=0,j=0,len=0,isPal=1;
	char tmpr,tmpl;
	
	cout<<"Hint: Key Enter Directly to Exit!"<<endl
		<<"Please enter potential palindrome:"<<endl;
		
	//get line including space form stdin
	getline(cin, tmp);
	len = tmp.size();
	
	// Can Key Enter without other characters to Exit!
	while(len!=0)
	{		
		i = 0;
		j = len-1;
		isPal = 1;
		
		while(i<len || j>=0)
		{
			while(!isalpha(tmp[i])) i++;
			while(!isalpha(tmp[j])) j--;
			
			// void the pointer i & j move over the range of String
			if(!(i<len || j>=0)) break;
			
			tmpr=tmp[i]; tmpl=tmp[j];
								
			if(toupper(tmpr)!=toupper(tmpl))
			{
					isPal = 0;
					break;
			}
			
			i++; j--;
		}
		

		if(isPal==1)	cout<<"Valid palindrome"<<endl;
		else	cout<<"Not palindrome"<<endl;
		
		//get line for next round in while loop
		getline(cin, tmp);
		len = tmp.size();	
	}

	return 0;
}
