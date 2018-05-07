#include"bag.h"


int main()
{
    Bag<int> a;

    //cout<<a.empty()<<endl;

    a.insert(7);
    a.insert(6);
    a.insert(1);
    a.insert(5);


    cout<<"Contains:"<<a.contains(7)<<endl;

    cout<<"test:"<<a.currentValue()<<endl;


    //cout<<a.empty()<<endl;



    cout<<a.size()<<endl;

    return 0;
}
