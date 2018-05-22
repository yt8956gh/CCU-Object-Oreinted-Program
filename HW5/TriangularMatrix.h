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
    vector<double> element;
    Matrix *tmpMatrix;


public:

    Matrix(int rank=2)
    {
        this->rank=rank;

        //make a empty Matrix for return before init
        elementNum = rank*(rank+1)/2;

        for(int i=0;i<elementNum;i++)
        {
            element.push_back(0);
        }

        init=mode=elementNum=0;

        //init_tmpMatrix(rank);

        cerr<<"Constructor"<<endl;
    }

    ~Matrix()
    {

        element.clear();
        tmpMatrix->element.clear();
        delete tmpMatrix;
        //element.shrink_to_fit();
        cerr<<"Destructor"<<endl;
    }

    Matrix(const Matrix& copy)
    {

        element.clear();
        rank = copy.rank;
        elementNum = copy.elementNum;
        mode = copy.mode;

         for(int i=0;i<copy.elementNum;i++)
        {
            element.push_back(copy.element.at(i));
        }

        init=1;

        //init_tmpMatrix(copy.rank);

        cerr<<"Copy constructor"<<endl;
    }


    void readMatrix()
    {
        double tmp=0;

        init = 1;

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

        element.clear();

        //element.resize(elementNum);//strange behavior

        cerr<<"input elements of the matrix:"<<endl;

        for(int i=0;i<elementNum;i++)
        {
            cin>>tmp;

            element.push_back(tmp);
        }

        tmpMatrix = new Matrix();

        init=1;
    }

    int size() const
    {
        return rank;
    }

    int mode_check() const
    {
        return mode;
    }

    Matrix& operator=(const Matrix & copy)
    {
        //將左邊的element清空
        element.clear();
        rank = copy.rank;
        elementNum = copy.elementNum;
        mode = copy.mode;

        //delete tmpMatrix;
        //init_tmpMatrix(rank);

        //將右邊寫入左邊
        for(int i=0;i<elementNum;i++)
        {
            element.push_back(copy.element.at(i));
        }

        init=1;

        return *this;
    }

    void init_tmpMatrix(int rank=2)
    {
        tmpMatrix = new Matrix(rank);

        tmpMatrix->mode = 1;//deflaut
        tmpMatrix->init = 1;
    }


    void test() const
    {
        for(int i=0;i<element.size();i++)
        {
            cout<<element.at(i)<<" ";
        }
        cout<<endl;
    }


    Matrix& operator+=(const Matrix & m)
    {
        if(init==0)
        {
            cerr<<"Please initialize Matrix with readMatrix()."<<endl;
            return *this;
        }
        else if(this->rank!=m.rank)
        {
            cout<<"# Please use += to matrix in same rank"<<endl<<endl;
            return *this;
        }
        else if(this->mode!=m.mode)
        {
            cout<<"# Please use += to matrix in same mode(upper/lower)"<<endl<<endl;
            return *this;
        }
        


        for(int i=0;i<elementNum;i++)
        {
            element.at(i)+=m.element.at(i);
        }


        return *this;
    }

    Matrix& operator-=(const Matrix& m)
    {

        if(init==0)
        {
            cerr<<"Please initialize Matrix with readMatrix()."<<endl;
            return *this;
        }
        else if(this->rank!=m.rank)
        {
            cout<<"# Please use -= to matrix in same rank"<<endl<<endl;
            return *this;
        }
        else if(this->mode!=m.mode)
        {
            cout<<"# Please use -= to matrix in same mode(upper/lower)"<<endl<<endl;
            return *this;
        }


        for(int i=0;i<elementNum;i++)
        {
            element.at(i)-=m.element.at(i);
        }

        return *this;
    }

    Matrix& operator*=(const Matrix& m)
    {

    }


    Matrix& operator*(const double number)
    {

        *tmpMatrix = *this;

        int i;

        for(i=0;i<elementNum;i++)
        {
            tmpMatrix->element.at(i)*=number;
        }

        return *tmpMatrix;
    }


    Matrix operator+(const Matrix& rt)
    {
        *tmpMatrix = rt;
        *tmpMatrix+=*this;
        return *tmpMatrix;
    }

    Matrix operator-(const Matrix& rt)
    {
        *tmpMatrix = rt;
        *tmpMatrix-=*this;
        return *tmpMatrix;
    }

    Matrix operator*(const Matrix& rt){};


    friend ostream& operator<<(ostream& out, const Matrix& x);
};



ostream& operator<<(ostream& out, const Matrix& x)
{

    int index=0,i=0,k=0,j=0,rank=x.size();


    //x.test();

    out<<endl;

    if(x.mode_check()==1)//(upper: 1, lower:0)
    {
        for(i=0;i<rank;i++)
        {

            for(k=0;k<(rank-i);k++)
            {
                out<<x.element.at(index++)<<'\t';
            }

            for(j=0;j<i; j++)
            {
                out<<"0\t";
            }

            out<<endl;
        }
    }
    else
    {
        for(i=0;i<rank;i++)
        {

            for(k=0;k<=i;k++)
            {
                out<<x.element.at(index++)<<'\t';
            }

            for(j=0;j<(rank-i-1); j++)
            {
                out<<"0\t";
            }

            out<<endl;
        }
    }


    return out;
}