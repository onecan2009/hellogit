#include <QCoreApplication>
#include <iostream>
using namespace std;

class Furniture
{
public:
    Furniture(){}
    void SetWeight(int i)
    {
        weight = i;
    }
    int GetWeight()
    {
        cout<<"The weight is:"<<weight<<endl;
        return weight;
    }
protected:
    int weight;
};


class Bed:virtual public Furniture

{
public:
    Bed(){}
    void Sleep(){cout<<"Sleeping"<<endl;}

};

class Sofa: virtual public Furniture
{
public:
    Sofa(){}
    void WatchTV(){cout<<"Watch TV"<<endl;}
};

class SleeperSofa:public Bed, public Sofa
{
public:
    SleeperSofa():Sofa(), Bed(){}
    void FoldOut(){cout<<"Fold out the sofa"<<endl;}
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        SleeperSofa ss;
        ss.SetWeight(20);
        ss.GetWeight();
    }
    return a.exec();
}
