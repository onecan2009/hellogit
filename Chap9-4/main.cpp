#include <QCoreApplication>
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    {
        vector<int> myVector(3, 10);
        myVector[2] = 125;
        myVector.push_back(256);
        cout << "size: " << myVector.size() << endl;
        vector<int>::iterator it;
        it = myVector.begin();
        it = myVector.insert(it, 200);
        it = myVector.insert(it+2, 300);
        for(it = myVector.begin(); it != myVector.end(); it++)
        {
            cout << " " << *it;
        }

        cout << endl;
        cout << "size: " << myVector.size() << endl;
    }
    return a.exec();
}
