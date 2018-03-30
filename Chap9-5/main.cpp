#include <QCoreApplication>
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        int player[] = {12, 9, 8, 23, 112, 39, 8, 27};
        list<int> myList;
        for(int i = 0; i < sizeof(player)/4; i++)
        {
            myList.push_back(player[i]);
        }
        list<int>::iterator it;
        for(it = myList.begin(); it != myList.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
        cout << "Remove 112" << endl;
        myList.remove(112);
        cout << "Sort" << endl;
        myList.sort();
        for(it = myList.begin(); it != myList.end(); it++)
        {
            cout << *it << " ";
        }
        /*for(int i = 0; i<myList.size(); i++)
        {
            cout<<"  "<<myList[i];
        }*/
        cout << endl;
        while(!myList.empty())
        {
            cout << "remove tail "<< myList.back() << "\n";
            myList.pop_back();
        }

    }
    
    return a.exec();
}
