#ifndef TRIANGULARMATRIX_H
#define TRIANGULARMATRIX_H


#include<iostream>
#include<vector>
#include<ctype.h>
#include "TriangularMatrix.h"

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

    Matrix(int rank=2);
    ~Matrix();
    Matrix(const Matrix&);
    void readMatrix();

    int size() const;
    int mode_check() const;    
    void test() const;

    double operator() (const int,const int)const;
    Matrix& operator=(const Matrix &);
    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*=(const Matrix&);
    Matrix& operator*(const double);
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator*(const Matrix&);

    friend ostream& operator<<(ostream& out, const Matrix& x);

    friend Matrix operator*(double s, const Matrix& rt);
};


#endif
