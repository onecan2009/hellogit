#include <QCoreApplication>
#include <iostream>

using namespace std;

class CPolygon
{
protected:
     int width, height;
public:
     void set_values (int a, int b)
     {
         width=a;
         height=b;
     }
     /*virtual*/ int area ()
     { return (0); }
};

class CRectangle: public CPolygon
{
public:
    int area ()
    {
        return (width * height);
    }
};

class CTriangle: public CPolygon
{
//public:
        int area ()
        {
            return (width * height / 2);
        }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    CRectangle rect;
    CTriangle trgl;
    CPolygon * ppoly1 = &rect; //pointer to derived class
    CPolygon * ppoly2 = &trgl; //pointer to base class
    ppoly1->set_values (4,5);
    ppoly2->set_values (4,5);
    cout <<" ply1:"<<ppoly1->area()<<"\n";
    cout <<" ply2:"<< ppoly2->area()<<"\n";

    return a.exec();
}
