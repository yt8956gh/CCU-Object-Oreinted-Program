#include<iostream>
#include "InternalNode.h"

using namespace std;

InternalNode::InternalNode(const int freq, Node *Lchild, Node *Rchild):Node(freq)
{
    this->Lchild = Lchild;
    this->Rchild = Rchild;

    //cerr<<"Internal Node Constructed"<<endl;
}
InternalNode::~InternalNode()
{
    //cerr<<"Internal Node Destructed"<<endl;
}

int InternalNode::getNodeType()
{
    return 1;//1: internal node
}

char InternalNode::getValue()
{
    //cerr<<"ERROR: Internal Node have no Value."<<endl;
    //cerr<<"Internal Node";

    
    return 0;
}
Node* InternalNode::getLChild()
{
    return Lchild;
}

Node* InternalNode::getRChild()
{
    return Rchild;
}
