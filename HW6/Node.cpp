#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(const int freq)
{
    this->freq = freq;
    //cerr<<"Node Constructed"<<endl;
}

Node::~Node()
{
    //cerr<<"Node Destructed"<<endl;
}

int Node::getFreq()
{
    return freq;
}
