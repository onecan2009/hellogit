#include <iostream>
#include "ring.h"
using namespace std;

Ring::Ring(int n)
{
    size = n;
    head = NULL;
    for(int i = 0; i < n; i++)
    {
        nod *pnod = new nod(i+1);
        if(head == NULL)
        {
            head = pnod;
            tail = pnod;
        }
        else
        {
            tail->next = pnod;
            pnod->prior = tail;
            tail = pnod;
        }
    }
    //灏炬寚閽堢殑next鎸囧悜澶寸粨鐐?
    tail->next = head;
    head->prior = tail;
    //寰幆閾捐〃寤虹珛瀹屾垚
}

//璁剧疆缂栧彿涓簄鐨勭粨鐐逛负璧峰缁撶偣
bool Ring::set_begin(int n)
{
    if(n > size)
        return false;
    nod *ptr = head;
    int flag = 0;
    while(1)
    {
       if(ptr->id == n)
       {
          begin = ptr;
          return true;
       }
      if(ptr->next->id <= ptr->id) //杞簡涓€鍦?
          return false;
      ptr = ptr->next;
    }
}

int Ring::left() const
{
    return size;
}

bool Ring::kick(int step)
{
    nod *ptr = begin;
    for(int i = 0; i < step; i++)
    {
        ptr = ptr->next;
    }
    nod *pri = ptr->prior;
    nod *nxt = ptr->next;
    pri->next = nxt;
    nxt->prior = pri;
    kicked = ptr->id;
    delete ptr;
    begin = nxt;
    size--;
}

void Ring::print_kicked()
{
    cout << "[ " << kicked  << " ]" << endl;
}

void Ring::print_left() //const
{
    nod *ptr = begin;
    for(int i = 0; i < size; i++)
    {
        if(0 == ((i)%10))//姣忚緭鍑?0涓暟瀛楁崲琛?
            cout << "\n";
        cout << ptr->id <<" ";
        ptr = ptr->next;
    }
    cout << "\n";
}
