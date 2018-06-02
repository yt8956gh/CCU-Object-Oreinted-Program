#include "HuffmanTree.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

HuffmanTree::HuffmanTree(const string& input)
{
    int i=0, index=0, table[200];//用table[(int)char]的方式，紀錄字元的出現次數

    // Initialization
    codeMaxLength = 0;
    memset(code_tmp,'\0',sizeof(code_tmp));

    for(i=0;i<200;i++)
    {
        table[i]=0;
    }

    // 如果不cast成int，會產生以下錯誤
    // comparison between signed and unsigned integer expressions
    for(i=0;i<(int)input.size();i++)//紀錄出現次數
    {
        index = input.at(i);

        if(index>=32 && index<=126)//spec規定只接收ASCII 32~126
        {
            table[index]++;
        }
        else cerr<<"ERROR: Illegal Input to HuffmanTree"<<endl;
    }

    vector<Node*> NodeTable;//暫時存放node指標
    vector<Node*>::iterator ptr;
    Node *Lptr,*Rptr,*NodePtr;

    for(i=0;i<200;i++)//依照各字元的出現次數，建構TerminalNode
    {
        if(table[i]!=0)
        {
            NodeTable.push_back(new TerminalNode(table[i],(char)i));
        }
    }

    sort(NodeTable.begin(),NodeTable.end(),cmp);  //NodeTable為小到大

    allTable = NodeTable;//複製所有指標到allTable，等到Destructed時刪除用


    // Build Huffman Tree
    // 1. 新建一個InternalNode，再挑選兩個最小的TerminalNode，設為InternalNode的左右子樹(freq較大的放左邊)。
    // 2. 將上述NodeTable中最小的兩個TerminalNode刪除。
    // 3. 將建好的internalNode丟進NodeTable （當作升序的stack）。
    // 4. 重複上述行為直到NodeTable只剩一個元素，也就是root。

    while(NodeTable.size()>=2)
    {
        Lptr = NodeTable.at(0);
        Rptr = NodeTable.at(1);

        NodeTable.erase(NodeTable.begin());
        NodeTable.erase(NodeTable.begin());

        NodePtr = new InternalNode(Lptr->getFreq()+Rptr->getFreq(), Lptr, Rptr);

        NodeTable.push_back(NodePtr);
        allTable.push_back(NodePtr);

        sort(NodeTable.begin(),NodeTable.end(),cmp);

    }

    root = *(NodeTable.begin());

    trace(root,-1,0);//因為第一個點是整顆樹的root，所以傳-1來告知trace

    vector<CODE*>::iterator code_ptr;

    //印出編碼表
    cout<<"----------CODE TABLE---------"<<endl;

    for(code_ptr = code_table.begin();code_ptr!=code_table.end();code_ptr++)
    {
        cout<<(*code_ptr)->symbol<<":"<<(*code_ptr)->code<<endl;
    }

    cout<<"-----------------------------"<<endl<<endl;

    codeMaxLength++;//因為level原本是拿來紀錄index的，所以要+1才會變成length
}

void HuffmanTree::trace(Node* parent, int level, char tmp)
{
    if(parent!=NULL)
    {
        if(level>=0)//避免在rot==parent時，把數字加入code_tmp
        {
            code_tmp[level] = tmp;
            code_tmp[level+1] = '\0';
        }

        CODE* ptr=NULL;

        //依據Node的類型決定行為
        //InternalNode:1
        //TerminalNodes:0
        if(parent->getNodeType())
        {
            trace(parent->getLChild(),level+1,'0');
            trace(parent->getRChild(),level+1,'1');
        }
        else//trace到TerminalNode，就紀錄該字元的編碼
        {
            ptr =  new CODE;//用來紀錄每一個字元的code
            ptr->symbol = parent->getValue();

            memset(ptr->code,'\0',sizeof(ptr->code));//Initialization
            strcpy(ptr->code, code_tmp);

            code_table.push_back(ptr);
        }

        if(level>=codeMaxLength) codeMaxLength = level;
    }
}

HuffmanTree::~HuffmanTree()
{
    vector<CODE*>::iterator code_ptr;

    for(code_ptr = code_table.begin();code_ptr!=code_table.end();code_ptr++)
    {
        delete *code_ptr;
    }

    vector<Node*>::iterator ptr;

    for(ptr = allTable.begin();ptr!=allTable.end();ptr++)
    {
        //刪除時必須用子類別的指標，要不然會刪不乾淨。
        if((*ptr)->getNodeType()) delete (InternalNode*) *ptr;
        else delete (TerminalNode*) *ptr;
    }

    //delete root;
    code_table.clear();
    allTable.clear();
}

bool HuffmanTree::cmp(Node* a, Node* b)
{
    return a->getFreq() < b->getFreq();
}

string HuffmanTree::encode(const string& s) const
{
    int i=0,legal=0;
    vector<CODE*>::const_iterator  ptr;
    string pattern;

    for(i=0;i<(int)s.size();i++)
    {
        legal=0;

        for(ptr=code_table.begin();ptr!=code_table.end();ptr++)//在code_table尋找對應編碼
        {
            if(s.at(i)==(*ptr)->symbol)
            {
                legal=1;
                pattern.append((*ptr)->code);
                break;
            }
        }

        if(legal==0)//找不到的話
        {
            cerr<<"ERROR: character "<<s.at(i)<<" cannot be encoded"<<endl;
            return string("");
        }
    }

    return pattern;
}

string HuffmanTree::decode(const string& s) const
{

    int i=0,legal=0,len = s.size(),index=0;
    vector<CODE*>::const_iterator  ptr;
    string pattern;

    while(index<len)
    {
        legal=0;

        for(i=1;i<=codeMaxLength;i++)//長詞優先
        {
            for(ptr=code_table.begin();ptr!=code_table.end();ptr++)//在code_table尋找對應編碼
            {
                if((index+i)>len) break;//如果index超出range

                if(!s.substr(index,i).compare((*ptr)->code))
                {
                    legal=1;
                    pattern.append(1,(*ptr)->symbol);
                    index+=i;
                    break;
                }
            }
        }

        if(legal==0)//找不到的話
        {
            cerr<<"ERROR: sequence "<<s<<" in "<<index<<" cannot be decoded"<<endl;
            return string("");
        }
    }

    return pattern;
}
