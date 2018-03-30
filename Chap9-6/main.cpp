#include <QCoreApplication>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    {
        queue<int> myqueue;
        int data;
        do
        {
            cin >> data;
            myqueue.push(data);
            cout << "queue length: " << myqueue.size() << endl;
            if(0 == data)
                    break;
        }while(1);
        while(myqueue.size())
        {
            cout << "queue first: " << myqueue.front() << " last: " << myqueue.back() << endl;
            myqueue.pop();
        }

    }
    return a.exec();
}
