#include <QCoreApplication>
#include <iostream>
using namespace std;

class Bed
{
public:
    Bed():weight(0){}
    void Sleep(){cout<<"Sleeping"<<endl;}
    void SetWeight(int i)
    {
        weight = i;
        cout<<"Set Weight from Bed"<<endl;
    }
protected :
    int weight;
};

class Sofa
{
public:
    Sofa():weight(0){}

    void WatchTV()
    {
        cout<<"Watch TV"<<endl;
    }

    void SetWeight(int i)
    {
        weight = i;
        cout<<"Set Weight from sofa"<<endl;
    }
protected:
    int weight;
};

class  SleeperSofa:public Bed, public Sofa
{
public:
    SleeperSofa(){}
    void FoldOut()
    {
        cout<<"Fold out the Sofa"<<endl;
    }

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        SleeperSofa ss;
        ss.WatchTV();
        ss.FoldOut();
        ss.Sleep();

        //ss.SetWeight();
        //ss.Bed::SetWeight(40);
        //ss.Sofa::SetWeight(50);
    }
    
    return a.exec();
}
