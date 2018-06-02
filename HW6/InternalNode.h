#ifndef INTERNALNODE_H
#define INTERNALNODE_H
#include "Node.h"


class InternalNode : public Node
{
private:
    Node *Lchild;
    Node *Rchild;
public:

    InternalNode(const int,Node*,Node*);
    ~InternalNode();

    int getNodeType();
    char getValue();
    Node* getLChild();
    Node* getRChild();
};

#endif
