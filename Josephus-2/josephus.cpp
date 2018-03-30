#include "josephus.h"
#include "ring.h"
#include <iostream>
using namespace std;
Josephus::Josephus()
{
     numOfBoys = 0;
     beginPos = 0;
     interval = 0;
}

void Josephus::Input()
{

    while(numOfBoys<2||beginPos<1||interval<1||interval>numOfBoys)
    {
        cout <<"please input \nnumber of boys, begin position,interval per count :\n" ;
        cin >> numOfBoys >> beginPos >>interval;
    }

    pRing = new Ring(numOfBoys);
}

void Josephus::GetWinner()
{
    pRing->set_begin(beginPos); //指定从哪个结点开始计数
    pRing->print_left(); //打印一下环链
    while(pRing->left() > 1) //循环链表中剩下的结点
    {
       pRing->kick(interval);   //删除数到的结点
       pRing->print_kicked();  //打印刚才删除的结点编号
       pRing->print_left();       //打印剩下的链表
       cout << "("<<pRing->left() << ")" << endl; //打印一下剩余结点个数
    }
    cout << "Winner is ";
    pRing->print_left();
}
