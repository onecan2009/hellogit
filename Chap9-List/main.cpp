#include <QCoreApplication>
#include <iostream>
using namespace std;

template <class T> class List
{
public:
    List();
    void Add(T&);
    void Remove(T&);
    T* Find(T&);
    void PrintList();
    ~List();
protected:
    struct Node
    {
        Node* pNext;
        T* pT;
    };
    Node* pFirst;
};

template <class T> List<T>::List()
{
    pFirst = 0;
}

template <class T>
void List<T>::Add(T& t)
{
    Node* temp = new Node;
    temp->pT = &t;
    temp->pNext = pFirst;
    pFirst = temp;
}

template<class T>
void List<T>::Remove(T& t)
{
    Node * q = 0;
    if(*(pFirst->pT)==t)
    {
        q = pFirst;
        pFirst = pFirst->pNext;
    }
    else
    {
        for(Node* p = pFirst; p->pNext;p=p->pNext)
        {

            if(*(p->pNext->pT) == t)
            {
                q = p->pNext;
                p->pNext = q->pNext;
                break;
            }

            if(q)
            {
                delete q->pT;
                delete q;
            }
        }

    }
}

template<class T>
T* List<T>::Find(T& t)
{
    for(Node* p = pFirst; p; p = p->pNext)
        if(*(p->pT) == t)
            return p->pT;
    return 0;

}

template <class T>
void List<T>::PrintList()
{
    for(Node* p = pFirst; p; p = p->pNext)
        cout<<*(p->pT)<<"  "<<endl;
}

template <class T>
List<T>::~List()
{
    Node* p;
    while(p = pFirst)
    {
        pFirst = pFirst->pNext;
        delete p->pT;
        delete p;
    }
    pFirst = 0;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    {
        List<int> myList1;
        int arr[5] = {200,300,400,23,96};
        for(int i = 0; i< 5; i++)
            myList1.Add(arr[i]);
        myList1.PrintList();
        cout<<myList1.Find(arr[3])<<"->"<<*myList1.Find(arr[3])<<endl;


        float f[5] = {2.3,9.24,101.3, 32.66,87.2};
        List<float> myList2;
        for(int i = 0; i< 5; i++)
            myList2.Add(f[i]);
        myList2.Remove(f[2]);
        myList2.PrintList();


    }
    
    return a.exec();
}
