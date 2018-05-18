#include<iostream>
#include<vector>

using namespace std;

class Matrix
{

private:
    int rank;
    int init;
    int mode;//(upper: 1, lower:0)
    int elementNum;
    vector<int> element;


public:

    Matrix(int rank=2)
    {
        this->rank=rank;
        init=mode=elementNum=0;
        cerr<<"Constructor"<<endl;
    }

    ~Matrix()
    {

        element.clear();
        //element.shrink_to_fit();
        cerr<<"Destructor"<<endl;
    }

    Matrix(const Matrix& copy)
    {
        cerr<<"Copy constructor"<<endl;
    }


    void readMatrix()
    {
        int tmp=0;

        while(1)
        {
            cout<<"Specify number of rows"<<endl;
            cin>>rank;
            if(rank>=2) break;
            else cout<<"# Please enter the number >=2"<<endl<<endl;
        }



        while(1)
        {
            cout<<"Is upper or lower triangular:(upper: 1, lower:0)"<<endl;
            cin>>mode;
            if(mode==1||mode==0) break;
            else cout<<"# Hint: upper=1, lower=0"<<endl<<endl;
        }
        
        elementNum = rank*(rank+1)/2;

        element.resize(elementNum);

        cout<<"input elements of the matrix:"<<endl;

        for(int i=0;i<elementNum;i++)
        {
            cin>>tmp;

            element.push_back(tmp);
        }
    }

    int size() const
    {
        return rank;
    }

    int mode_check() const
    {
        return mode;
    }


    Matrix& operator+=(const Matrix & m)
    {
        if(this->mode!=m.mode_check()||this->rank!=m.size())
        {
            cout<<"# Please use += to matrix in same specification"<<endl<<endl;
            return *this;
        }


        for(int i=0;i<elementNum;i++)
        {
            element.at(i)+=m.element.at(i);
        }

    }

    Matrix& operator-=(const Matrix& m)
    {

        if(this->mode!=m.mode_check()||this->rank!=m.size())
        {
            cout<<"# Please use -= to matrix in same specification"<<endl<<endl;
            return *this;
        }


        for(int i=0;i<elementNum;i++)
        {
            element.at(i)-=m.element.at(i);
        }
    };

    Matrix& operator*=(const Matrix& m)
    {

    };



};