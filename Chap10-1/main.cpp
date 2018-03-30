#include <QCoreApplication>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ofstream f1("C:\\abc.txt");

    if(f1)
    {
        f1<<"Name: "<<"Cindy"<<endl;
        f1<<"Address: "<<"Shanghai Pudong new district"<<endl;
        f1.close();
        cout<<"File write successfully!"<<endl;
    }
    return a.exec();
}
