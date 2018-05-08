#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<algorithm>


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

//friend void combine();


private:
    struct node<ItemType>*first,*finger;
    int item_num,iterator_num;
    ItemType *empty_obj;


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

        empty_obj = new ItemType;
        memset(empty_obj ,'\0',sizeof(empty_obj));


        cout<<"Bag constructed\n";
    }



    Bag(const Bag<ItemType>& copy)
    {
        this->first= new struct node<ItemType>;
        first->contain = NULL;
        first->left = first;
        first->right = first;

        this->finger = NULL;//avoid trace node before initializing iterator
        item_num=iterator_num=0;

        empty_obj = new ItemType;
        memset(empty_obj ,'\0',sizeof(empty_obj));


        struct node<ItemType>* ptr=NULL;
        ptr = (copy.first)->right;

        while(ptr!=copy.first)
        {
            insert(*(ptr->contain));
            ptr=ptr->right;
        }
        cout<<"Bag copy constructed\n";
    }





    ~Bag()
    {

        deleteAll();

        delete first;
        //delete empty_obj;

        cout<<"Bag destructed\n";
    }


    Bag<ItemType>& operator=(const Bag<ItemType>& a)
    {
        struct node<ItemType> *ptr=NULL;

        ptr=first;

        if((ptr->right)!=ptr)//左邊是非空
        {
           deleteAll();
        }


        ptr = (a.first)->right;


        while(ptr!=(a.first))
        {
            insert(*(ptr->contain));
            ptr = ptr->right;
        }

        return *this;
    }


    void  deleteAll(void)
    {
        int item_found=0;
        struct node<ItemType> *ptr=NULL,*del=NULL,*LEFT=NULL,*RIGHT=NULL;

        finger=NULL;
        iterator_num=item_num=0;

        ptr=first->right;

        while(ptr!=first)
        {

            //cerr<<"enter while"<<endl;
            del=ptr;
            ptr=ptr->right;

            //將del(被刪除的node)的兩邊重新接上
            LEFT = del->left;
            RIGHT = del->right;

            LEFT->right = RIGHT;
            RIGHT->left = LEFT;

            //cerr<<"delete:"<<*(del->contain)<<endl;

            delete del->contain;//delete ItemType object
            del->contain=NULL;

            delete del;//delete node contain
            del=NULL;


        }
    }



    bool empty() const
    {
        if(first == (first->right)) return true;
        else return false;
    }
    //如果背包是空的就回傳true，否則回傳false


    int size() const
    {
        return item_num;
    }
    //回傳背包中物品總數


    int uniqueSize() const
    {
        vector<ItemType> checked;
        typename vector<ItemType>::iterator result;//默認為變量，強制解讀為template

        int variety=0;

        struct node<ItemType>* ptr = first->right;

        ItemType now;


        if(ptr==first)
        {
            return 0;
        }

        for(int i=0;i<item_num;i++)
        {
            now = *(ptr->contain);

            result = find(checked.begin(),checked.end(),now);

            if(result == checked.end())//not found
            {
                checked.push_back(now);

                variety++;
            }

            ptr = ptr->right;

        }


        checked.clear();
        //checked.shrink_to_fit();// free vector

        return variety;
    }
    //回傳背包中相異物品數



    bool insert(const ItemType& value)
    {

        finger=NULL;
        iterator_num=0;

        struct node<ItemType>* new_node = new struct node<ItemType>;

        new_node->right = first;
        new_node->left = first->left;
        (first->left)->right = new_node;
        first->left = new_node;

        new_node->contain = new ItemType;
        *(new_node->contain) = value;

        ++item_num;

        return true;

    }
    //將一個物品value加入背包中，成功加入便回傳true




    int erase(const ItemType& value)
    {
        int item_counter=0;
        struct node<ItemType> *ptr=NULL,*del=NULL,*LEFT=NULL,*RIGHT=NULL;

        finger=NULL;
        iterator_num=0;

        ptr=first->right;

        if(ptr==first)//往first左右走會走回first，代表背包為空
        {
            return 0;
        }

        while(ptr!=first)
        {
            del=ptr;

            item_counter++;


            if(*(del->contain)==value)
            {
                //將del(被刪除的node)的兩邊重新接上
                LEFT = del->left;
                RIGHT = del->right;

                LEFT->right = RIGHT;
                RIGHT->left = LEFT;


                delete del->contain;//delete ItemType object
                del->contain=NULL;

                delete del;//delete node contain
                del=NULL;

                --item_num;
                break;
            }

            ptr = ptr->right;
        }

        if(ptr==first) return 0;
        else return item_counter;
    }
    //移除背包中一個物品value，回傳移除的是第幾個物品，若背包中沒這樣物品則回傳0

    int eraseAll(const ItemType& value)
    {

        int item_found=0;
        struct node<ItemType> *ptr=NULL,*del=NULL,*LEFT=NULL,*RIGHT=NULL;


        finger=NULL;
        iterator_num=0;

        ptr=first->right;

        if(ptr==first)//往first左右走會走回first，代表背包為空
        {
            return 0;
        }


        while(ptr!=first)
        {
            del=ptr;


            if(*(del->contain)==value)
            {
                //將del(被刪除的node)的兩邊重新接上
                LEFT = del->left;
                RIGHT = del->right;

                LEFT->right = RIGHT;
                RIGHT->left = LEFT;


                delete del->contain;//delete ItemType object
                del->contain=NULL;

                delete del;//delete node contain
                del=NULL;

                item_found++;
            }

            ptr=ptr->right;
        }

        //cerr<<"ITEM_FOUND:"<<item_found<<endl;
        this->item_num = item_num - item_found;


        return item_found;
    }
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



    int count(const ItemType& value) const
    {
        if(item_num==0) return 0;

        struct node<ItemType> *ptr=first->right;
        int counter=0;

        while(ptr->contain !=NULL)
        {
            if(*(ptr->contain)==value)
            {
                counter++;
            }

            ptr=ptr->right;
        }

        return counter;

    }
    //回傳物品value在背包中的數量

    void start()
    {
        if((this->first)->right==NULL && item_num==0)//item count==NULL;
        {
            cout<<"Please input item"<<endl;
        }
        else
        {
            finger = first->right;
            iterator_num=1;
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
        else if(finger==first)
        {
            finger=NULL;
            iterator_num=0;
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


    bool ended() const
    {
        if(finger==NULL) return true;
        else return false;
    }
    //如果手指沒有指向任何物品就回傳true，否則回傳false



    const ItemType& currentValue() const
    {
        if(finger==NULL||finger==first)
        {
            cerr<<"Please initializes"<<endl;
            return *empty_obj;//失敗時回傳填滿\0的Itemtype
        }

        return *(finger->contain);
    }
    //回傳手指指到的物品
    //若更動過背包中的物品(insert, erase, eraseAll)，必須先初始化才能使用呼叫currentValue()
    //若還未將手指初始化就呼叫currentValue()，印Please initializes，並且程式不能壞掉



    int currentCount() const
    {
        if(finger==NULL)
        {
            cout<<"Please initializes"<<endl;
            return 0;
        }

        return iterator_num;
    }
    //回傳手指指到的是第幾個物品
    //若更動過背包中的物品(insert, erase, eraseAll)，必須先初始化才能使用呼叫currentCount()
    //若還未將手指初始化就呼叫currentCount，印Please initializes，回傳0，並且程式不能壞掉f

    void trace()
    {
        int i=0;
      struct node<ItemType>* ptr = first->left;

        while(ptr!=first)
        {
            cout<<"\t"<<++i<<": "<<*(ptr->contain)<<endl;
            ptr = ptr->left;
        }
    }
};



template<class ItemType>
void combine(Bag<ItemType>& bag1, Bag<ItemType>& bag2, Bag<ItemType>& result)
{
    //bag1.trace();

    result.deleteAll();

    bag1.start();
    bag2.start();

    for(int i=0;i<bag1.size();i++)
    {
      result.insert(bag1.currentValue());
      bag1.next();
    }

    for(int i=0;i<bag2.size();i++)
    {
      result.insert(bag2.currentValue());
      bag2.next();
    }

    return;
}

template<class ItemType>
void subtract(Bag<ItemType>& bag1, Bag<ItemType>& bag2, Bag<ItemType>& result)
{
    result = bag1;

    bag2.start();

    for(int i=0;i<bag2.size();i++)
    {
        result.erase(bag2.currentValue());
        bag2.next();
    }

}
