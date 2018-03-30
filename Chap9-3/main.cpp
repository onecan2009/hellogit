#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int> num;
    int element;
    while(cin>>element && element != 0)
        num.push_back(element);
    sort(num.begin(),num.end());
    for(int i = 0; i<num.size();i++)
        cout<<num[i]<<"\n";
    
    return a.exec();
}
