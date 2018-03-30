#include <QCoreApplication>
#include <iostream>
using namespace std;


inline int isnumber(char ch)
{
    return (ch>='0' && ch<='9')?1:0;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char c;
    cout<<"Please input a string"<<endl;
    while ((c=cin.get())!='\n')
    {
        if(isnumber(c))
            cout<<"You entered a digit \n";
        else
            cout<<" you entered a non-digit \n";
    }

    return a.exec();
}
