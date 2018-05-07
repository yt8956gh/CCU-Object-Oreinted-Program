#include"bag.h"
#include<string>


int main()
{
    Bag<int> a;
    Bag<string> b;

    //cout<<a.empty()<<endl;

    a.insert(7);
    a.insert(6);
    a.insert(6);
    a.insert(6);
    a.insert(6);
    a.insert(6);
    a.insert(1);
    a.insert(5);
    a.insert(3);

    b.insert("app");
    b.insert("app");
    b.insert("app");
    b.insert("app");
    b.insert("app");
    b.insert("app");
    b.insert("pooh");
    b.insert("pooh");
    b.insert("pooh");
    b.insert("piget");
    b.insert("piget");
    b.insert("piget");
    b.insert("pooh");
    b.insert("pooh");
    b.insert("owl");


    cout<<"UNIQUE SIZE:"<<a.uniqueSize()<<endl;

    cout<<"UNIQUE SIZE:"<<b.uniqueSize()<<endl;


    cout<<"Contains:"<<a.contains(7)<<endl;

    cout<<"COUNT 6: "<<a.count(6)<<endl;

    cout<<"COUNT app: "<<b.count("app")<<endl;

    //cout<<"delete num of app: "<<b.eraseAll("app")<<endl;

    cout<<"delete app "<<b.erase("app")<<endl;

    cout<<"COUNT app: "<<b.count("app")<<endl;

    //cout<<"COUNT app: "<<b.count("app")<<endl;


    cout<<"COUNT pooh: "<<b.count("pooh")<<endl;

    cout<<"delete pooh "<<b.erase("pooh")<<endl;
    cout<<"delete pooh "<<b.erase("pooh")<<endl;
    cout<<"delete pooh "<<b.erase("pooh")<<endl;
    cout<<"delete pooh "<<b.erase("pooh")<<endl;

    cout<<"COUNT pooh: "<<b.count("pooh")<<endl;


    a.start();
    b.start();

    cout<<"test int:"<<a.currentValue()<<endl;

    a.next();
    cout<<"test int:"<<a.currentValue()<<endl;

    a.next();
    cout<<"test int:"<<a.currentValue()<<endl;


    cout<<"test string:"<<b.currentValue()<<endl;



    Bag<string> c = b;

    cout<<"b size:"<<b.size()<<endl;

    cout<<"c size:"<<c.size()<<endl;


    //cout<<a.empty()<<endl;



    cout<<a.size()<<endl;

    return 0;
}
