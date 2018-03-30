#include <QCoreApplication>
#include <iostream>
#include <stdlib.h>

using namespace std;
class Matrix;
class Vector;
Vector Multiply(Matrix& m, Vector & v);
class Vector
{
public:
    Vector(int s);
    ~Vector(){delete[] v;}
    Vector(Vector& vec)
    {
        v = new int[sz = vec.sz];
        memcpy((void*)v,(void*)vec.v,sz*sizeof(int));
    }
    int Size(){return sz;}
    void Display();
    int& Elem(int);
    friend Vector Multiply(Matrix& m, Vector& v);
protected:
    int* v;
    int sz;
};

Vector::Vector(int s)
{
    if(s<=0)
    {
        cout<<"Bad vector size"<<endl;
        exit(1);
    }
    sz = s;
    v = new int[s];
}

int& Vector::Elem(int i)
{
    if(i<0||sz<=i)
    {
        cout<<"Vector index out of range"<<endl;
        exit(1);
    }
    return v[i];
}

void Vector::Display()
{
    for(int i = 0; i<sz; i++)
        cout<<v[i]<<"  ";
    cout<<endl;
}


class Matrix
{
public:
    Matrix(int, int);
    Matrix(Matrix& mat);
    ~Matrix(){delete[] m;}
    int& Elem(int, int);
    int Sizel(){return szl;}
    int SizeR(){return szr;}
    void Display();

    friend Vector Multiply(Matrix& m, Vector& v);
protected:
    int* m;
    int szl;
    int szr;
};

Matrix::Matrix(int i, int j)
{
    if(i<=0||j<=0)
    {
        cout<<"Bad Matrix size."<<endl;
        exit(1);
    }
    szl = i;
    szr = j;
    try
    {
        m = new int[i*j];
    }
    catch(...)
    {
        cout<<"error"<<endl;
    }

}

Matrix::Matrix(Matrix& mat)
{
    szl = mat.szl;
    szr = mat.szr;
    m = new int[szl*szr];
    memcpy((void*)m, (void*) mat.m,szl*szr*sizeof(int));
}

int& Matrix::Elem(int i, int j)
{
    if(i<0||szl<=i||szr<=j)
    {
        cout<<"Matrix index out of range";
        exit(1);
    }
    return m[i*szr+j];
}

void Matrix::Display()
{
     for(int i = 0; i < szl; i++)
     {
         for(int j = 0; j < szr; j++)
         {
              cout<<m[i,j];
         }
         cout<<endl;
      }
}


Vector Multiply(Matrix& m, Vector & v)
{
    if(m.szr!= v.sz)
    {
        cout<<"bad multiplying Matrix with Vector."<<endl;

    }
    Vector r(m.szl);
    for(int i = 0; i<m.szl;i++)
    {
        r.v[i] = 0;
        for(int j = 0; j < m.szl; j++)
            r.v[i] += m.m[i*m.szr + j]*v.v[j];
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        Matrix ma(4,3);

        ma.Elem(0,0) = 1;
        ma.Elem(0,1) = 2;
        ma.Elem(0,2) = 3;

        ma.Elem(1,0) = 0;
        ma.Elem(1,1) = 1;
        ma.Elem(1,2) = 2;

        ma.Elem(2,0) = 1;
        ma.Elem(2,1) = 1;
        ma.Elem(2,2) = 3;

        ma.Elem(3,0) = 1;
        ma.Elem(3,1) = 2;
        ma.Elem(3,2) = 1;

        ma.Display();
        /*Vector ve(3);
        ve.Elem(0) = 2; ve.Elem(1) = 1; ve.Elem(2) = 0;
        ve.Display();
        Vector va(3);
        va = Multiply(ma,ve);
        va.Display();*/
        cout<<"Finished."<<endl;
    }
    return a.exec();
}
