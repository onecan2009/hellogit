#include <QCoreApplication>
#include<iostream>
#include <algorithm>
#include <stack>

using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        stack<int> mystack;
        mystack.push(10);
        mystack.push(20);
        mystack.push(30);
        mystack.top() -= 5;
        cout << "mystack.top() is now " << mystack.top() << endl;
        mystack.pop();
        if(mystack.empty())
            cout << "mystack is empty." << endl;
        cout << "mystack.top() is now " << mystack.top() << endl;
        mystack.pop();
        if(mystack.empty())
            cout << "mystack is empty." << endl;
        cout << "mystack.top() is now " << mystack.top() << endl;
        mystack.pop();
        if(mystack.empty())
            cout << "mystack is empty." << endl;
        // if we try top,error occurs
        // cout << "mystack.top() is now " << mystack.top() << endl;
        // mystack.pop();
    }
    return a.exec();
}
