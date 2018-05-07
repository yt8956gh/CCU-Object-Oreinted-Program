#include<iostream>
#include<stdlib.h>
#include<string>


using namespace std;



template<class ItemType> 
struct node
{
    ItemType* contain;
    struct node<ItemType>* left;
    struct node<ItemType>* right;
};



template<class ItemType>
class Bag
{      

private:
    struct node<ItemType>*first,*finger;
    int item_num,iterator_num;


public:
    Bag()
    {

        // initialization for hand node ptr
        this->first= new struct node<ItemType>;
        first->contain = NULL;
        first->left = first;
        first->right = first;

        this->finger = NULL;//avoid trace node before initializing iterator
        item_num=iterator_num=0;


        cout<<"Bag constructed\n";
    }

    ~Bag()
    {
        cout<<"Bag destructed\n";
    }


    bool empty() const
    {
        if(item_num==0) return true;
        else return false;
    }
    //如果背包是空的就回傳true，否則回傳false
    int size() const
    {
        return item_num;
    }
    //回傳背包中物品總數
    int uniqueSize() const;
    //回傳背包中相異物品數
    bool insert(const ItemType& value)
    {
        struct node<ItemType>* new_node = new struct node<ItemType>;

        new_node->right = first;
        new_node->left = first->left;
        (first->left)->right = new_node;
        first->left = new_node;

        new_node->contain = new ItemType;
        *(new_node->contain) = value;

        ++item_num;

        finger = NULL;

        return true;

    }
    //將一個物品value加入背包中，成功加入便回傳true
    int erase(const ItemType& value);
    //移除背包中一個物品value，回傳移除的是第幾個物品，若背包中沒這樣物品則回傳0
    int eraseAll(const ItemType& value);
    //移除所有物品value，回傳移除的數量
    bool contains(const ItemType& value) const
    {
        if((this->first)->right==NULL && item_num==0)//item count==NULL;
        {
            return false;
        }

        struct node<ItemType> *ptr = (this->first)->right;


        for(int i=0;i<item_num;i++)
        {
            if(*(ptr->contain) == value)
            {
                return true;
            }

            ptr = ptr->right;
        }

        return false;
    }
    //如果背包中包含物品value就回傳true，否則回傳false


    int count(const ItemType& value) const;


    void start()
    {
        if((this->first)->right==NULL && item_num==0)//item count==NULL;
        {
            cout<<"Please input item"<<endl;
        }
        else
        {
            finger = first->right;
            iterator_num=0;
        }
    }
    //初始化手指，將手指指到第一個物品
    //若包包為空，印Please input item，並且程式不能壞掉


    void next()
    {
        if(finger==NULL)//代表尚未初始化
        {
            cout<<"Please initializes"<<endl;
            return;
        }


        if((finger->right)!=NULL)
        {
            finger = finger->right;
            iterator_num++;
        }
    }
    //將手指指到下一個物品
    //若更動過背包中的物品(insert, erase, eraseAll)，必須先初始化才能使用呼叫next()
    //若還未將手指初始化就呼叫next()，印Please initializes，並且程式不能壞掉
    //若已經走訪完畢，讓手指不再指向任何物品


    bool ended() const;
    //如果手指沒有指向任何物品就回傳true，否則回傳false



    const ItemType& currentValue() const
    {
        if(finger==NULL)
        {
            cout<<"Please initializes"<<endl;
            return *(first->contain);
        }

        return *(finger->contain);


    }
    //回傳手指指到的物品
    //若更動過背包中的物品(insert, erase, eraseAll)，必須先初始化才能使用呼叫currentValue()
    //若還未將手指初始化就呼叫currentValue()，印Please initializes，並且程式不能壞掉
    int currentCount() const
    {
        return iterator_num;
    }
    //回傳手指指到的是第幾個物品
    //若更動過背包中的物品(insert, erase, eraseAll)，必須先初始化才能使用呼叫currentCount()
    //若還未將手指初始化就呼叫currentCount，印Please initializes，回傳0，並且程式不能壞掉


};
