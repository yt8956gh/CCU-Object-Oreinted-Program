#include <iostream>
#include "TerminalNode.h"

using namespace std;

TerminalNode::TerminalNode(int freq, char value):Node(freq)
{
    this->value = value;
    //cerr<<this->value<<" : "<<getFreq()<<endl;
    //cerr<<"Terminal Constructor"<<endl;
}

TerminalNode::~TerminalNode()
{
    //cerr<<"Terminal Destructor"<<endl;
}

int TerminalNode::getNodeType()
{
    return 0;
}

char TerminalNode::getValue()
{
    return value;
}

Node* TerminalNode::getLChild()
{
    cerr<<"# Encounter Termianl Node:"<<getValue()<<endl;
    return NULL;
}

Node* TerminalNode::getRChild()
{
    cerr<<"# Encounter Termianl Node:"<<getValue()<<endl;
    return NULL;
}
