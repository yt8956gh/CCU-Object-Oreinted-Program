#ifndef NODE_H
#define NODE_H


class Node
{
private:
    int freq;  // 儲存 terminal node 的字頻，或 internal node 所有子節點的字頻總和

public:
    Node(const int);
    ~Node();
    int getFreq();
    virtual int getNodeType()=0;
    virtual char getValue()=0;
    virtual Node* getLChild()=0;
    virtual Node* getRChild()=0;
};


#endif
