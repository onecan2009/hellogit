#include <QCoreApplication>
#include <iostream>
using namespace std;

class Emp
{public:
    Emp();
    void Display();
    ~Emp();
private:
    int age;
    float height;
    float weight;};
Emp::Emp()
{    age = 18;
    height = 1.70;
    weight = 60;}
Emp::~Emp()
{    cout<<"Destructor executed!"<<endl;}
void Emp::Display()
{    cout<<"age: "<<age<<"\n";
    cout<<"height: "<<height<<"m\n";
    cout<<"weight: "<<weight<<"kg\n";}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        Emp e;
        e.Display();
   }
    //int i = 0;
    //i ++;
    
    return a.exec();
}
