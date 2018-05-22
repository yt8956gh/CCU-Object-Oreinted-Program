#include<iostream>
#include<vector>
#include<ctype.h>

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
    Matrix *emptyMatrix;


public:

    Matrix(int rank=2)
    {
        this->rank=rank;

        //make a empty Matrix for return before init
        elementNum = rank*(rank+1)/2;

        tmpMatrix=NULL;


        for(int i=0;i<elementNum;i++)
        {
            element.push_back(0);
        }

        init=mode=elementNum=0;

        cerr<<"Constructor"<<endl;
    }

    ~Matrix()
    {

        this->element.clear();

        if(tmpMatrix!=NULL)
        {
            tmpMatrix->element.clear();
            delete tmpMatrix;
        }

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

        tmpMatrix = new Matrix;

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

        if(tmpMatrix == NULL)
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

        //將右邊寫入左邊
        for(int i=0;i<elementNum;i++)
        {
            element.push_back(copy.element.at(i));
        }


        if(tmpMatrix == NULL) tmpMatrix = new Matrix();

        init=1;

        return *this;
    }

    void test() const
    {
        for(int i=0;i<element.size();i++)
        {
            cout<<element.at(i)<<" ";
        }
        cout<<endl;
    }


    double operator() (const int row,const int column)const
    {
        int index=0,i=0;

        if(row>rank||column>rank)
        {
            cerr<<"# ERROR: Out of range in Matrix"<<endl<<endl;
            return 0;
        }
        else if(init==0)
        {
            cerr<<"Please initialize Matrix with readMatrix()."<<endl;
            return 0;
        }

        if(mode==1)//upper
        {
            if((row+column-1)<=rank)
            {
                for(i=(row-1);i>0;i--)
                {
                    index+=(rank-i+1);
                }

                index+=column;

                index-=1;//使index變成vector的格式

                return element.at(index);
            }

            else return 0;

        }
        else
        {
          if((row+column)>rank)
          {
              for(i=0;i<row;i++)
              {
                  index+=i;
              }

              index+=column;

              index-=1;//使index變成vector的格式

              return element.at(index);
          }
          else return 0;
        }

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


        if(init==0)
        {
            cerr<<"Please initialize Matrix with readMatrix()."<<endl;
            return *this;
        }
        else if(this->rank!=m.rank)
        {
            cout<<"# Please use *= to matrix in same rank"<<endl<<endl;
            return *this;
        }
        else if(this->mode!=m.mode)
        {
            cout<<"# Please use *= to matrix in same mode(upper/lower)"<<endl<<endl;
            return *this;
        }

        double *tmpArray = new double[elementNum];
        int i=0,k=0,j=0,index=0,row=0,column=0;
        double number=0;


        if(mode==1)//upper
        {
            for(row=1;row<=rank;row++)//row
            {
                for(column=1;column<=rank;column++)//column
                {
                    index=number=0;

                    if((row+column-1)<=rank)
                    {
                        for(j=1;j<=rank;j++)//用來trace當前的row & column
                        {
                            number += (*this)(row,j)*m(j,column);
                        }
                    }
                    else continue;

                    cerr<<"row:"<<row<<"\tcolumn:"<<column<<" "<<number<<endl;

                    //使index變成vector的格式
                    for(i=(row-1);i>0;i--)
                    {
                        index+=(rank-i+1);
                    }
                    index+=column;
                    index-=1;

                    if(index>elementNum)
                    {
                        cerr<<"OUT OF RANGE"<<endl;
                    }
                    else tmpArray[index]=number;
                }
            }

        }
        else
        {
            for(row=1;row<=rank;row++)//row
            {
                for(column=1;column<=rank;column++)//column
                {
                    index=number=0;

                    if((row+column)>rank)
                    {
                        for(j=1;j<=rank;j++)//用來trace當前的row & column
                        {
                            number += (*this)(row,j)*m(j,column);
                        }
                    }
                    else continue;

                    //使index變成vector的格式
                    for(i=0;i<row;i++)
                    {
                        index+=i;
                    }

                    index+=column;
                    index-=1;

                    if(index>elementNum)
                    {
                        cerr<<"OUT OF RANGE"<<endl;
                    }
                    else tmpArray[index]=number;
                }
            }
        }

        for(i=0;i<elementNum;i++)
        {
            element.at(i) = tmpArray[i];
        }

        delete [] tmpArray;

        return *this;

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
