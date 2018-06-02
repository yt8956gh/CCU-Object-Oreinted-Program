#ifndef TERMINALNODE_H
#define TERMINALNODE_H
#include "Node.h"


class TerminalNode : public Node
{
private:
    char value;
public:

    TerminalNode(int,char);
    ~TerminalNode();

    int getNodeType();
    char getValue();
    Node* getLChild();
    Node* getRChild();
};

#endif
