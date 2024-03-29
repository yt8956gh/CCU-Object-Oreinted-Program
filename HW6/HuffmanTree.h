#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include "InternalNode.h"
#include "TerminalNode.h"
#include <string>
#include <vector>


using namespace std;

typedef struct code_table
{
    char symbol;
    char code[100];
}CODE;


class HuffmanTree
{
private:
    vector<CODE*> code_table;//用來紀錄每一個字元的code
    vector<Node*> allTable;
    Node *root;
    char code_tmp[100];
    int codeMaxLength;

public:
    HuffmanTree(const string&);

    ~HuffmanTree();

    string encode(const string& s) const;

    string decode(const string& s) const;

    void trace(Node*, int, char);

    static bool cmp(Node*, Node*);

};

#endif
