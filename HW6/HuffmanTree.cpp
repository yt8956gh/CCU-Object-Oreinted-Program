#include "HuffmanTree.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;

HuffmanTree::HuffmanTree(const string& input)
{
    int i=0,index=0;
    int table[200];//紀錄單字的出現次數
    int charNum=0;
    codeMaxLength = 0;

    memset(code_tmp,'\0',sizeof(code_tmp));

    for(i=0;i<200;i++)
    {
        table[i]=0;
    }

    for(i=0;i<input.size();i++)//紀錄出現次數
    {
        index = input.at(i);
        if(index>=32 && index<=126)
        {
            table[index]++;
            charNum++;
        }
        else cerr<<"ERROR: Illegal Input to HuffmanTree"<<endl;
    }

    vector<Node*> NodeTable,allTable;
    vector<Node*>::iterator ptr;
    Node *Lptr,*Rptr, *NodePtr;
    int Counter=0;

    for(i=0;i<200;i++)//依照各字元的出現次數，建構TerminalNode
    {
        if(table[i]!=0)
        {
            NodeTable.push_back(new TerminalNode(table[i],(char)i));
        }
    }

    sort(NodeTable.begin(),NodeTable.end(),cmp);

    allTable = NodeTable;//複製一份等到Destructed時刪除用

    i=0;

    //Build HuffmanTree
    //1.挑選兩個最小的TerminalNode丟到internalNode底下
    //2.建樹時，freq較大的放左邊
    //3.NodeTable為升序排列
    while(NodeTable.size()>=2)
    {
        //cout<<"Round: "<<i++<<"----------"<<endl;
        //cerr<<"NodeTable.size():"<<NodeTable.size()<<endl;

        Lptr = NodeTable.at(0);
        Rptr = NodeTable.at(1);

        NodeTable.erase(NodeTable.begin());
        NodeTable.erase(NodeTable.begin());

        NodePtr = new InternalNode(Lptr->getFreq()+Rptr->getFreq(), Lptr, Rptr);

        NodeTable.push_back(NodePtr);
        allTable.push_back(NodePtr);

        sort(NodeTable.begin(),NodeTable.end(),cmp);

        /*
        for(ptr = NodeTable.begin(); ptr!=NodeTable.end();ptr++)
        {
            //iterator視同指標，需要*來取值
            cout<<(*ptr)->getValue()<<":"<<(*ptr)->getFreq()<<endl;
        }
        cout<<endl;
        */
    }

    root = *(NodeTable.begin());

    //cerr<<"Root:"<<root->getFreq()<<endl;

    trace(root,-1,0);

    vector<CODE*>::iterator code_ptr;

    cout<<"----------CODE TABLE---------"<<endl;

    for(code_ptr = code_table.begin();code_ptr!=code_table.end();code_ptr++)
    {
        cout<<(*code_ptr)->symbol<<":"<<(*code_ptr)->code<<endl;
    }

    codeMaxLength++;
    cout<<"DEEP:"<<codeMaxLength<<endl;

}

void HuffmanTree::trace(Node* parent, int level, char tmp)
{
    //cerr<<"Level:"<<level<<endl;
    //cerr<<"tmp:"<<tmp<<endl;
    if(parent!=NULL)
    {
        //cerr<<parent->getFreq()<<endl;

        if(level>=0)
        {
            code_tmp[level] = tmp;
            code_tmp[level+1] = '\0';
        }

        CODE* ptr;

        if(parent->getNodeType())//InternalNode:1
        {
            trace(parent->getLChild(),level+1,'0');
            trace(parent->getRChild(),level+1,'1');
        }
        else//TerminalNodes:0
        {
            //cerr<<code_tmp<<endl;
            ptr =  new CODE;
            ptr->symbol = parent->getValue();
            strcpy(ptr->code, code_tmp);

            code_table.push_back(ptr);
        }

        if(level>=codeMaxLength) codeMaxLength = level;
    }
}



bool HuffmanTree::cmp(Node* a, Node* b)
{
    return a->getFreq() <= b->getFreq();
}

HuffmanTree::~HuffmanTree()
{

}

string HuffmanTree::encode(const string& s) const
{
    int i=0,legal=0;
    vector<CODE*>::const_iterator  ptr;
    string pattern;

    for(i=0;i<s.size();i++)
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
    char tmp[100];

    while(index<len)
    {
        legal=0;

        for(i=1;i<=codeMaxLength;i++)//長詞優先
        {
            for(ptr=code_table.begin();ptr!=code_table.end();ptr++)//在code_table尋找對應編碼
            {
                if((index+i)>len) break;


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
