#include "josephus.h"
#include "ring.h"
#include <iostream>
using namespace std;

Josephus::Josephus(int boys, int begin, int m)
{    while(boys<2||begin<1||m<1||m>boys)
    {
        cout <<"please input \nnumber of boys, begin position,interval per count :\n" ;
        cin >> boys >> begin >>m;
    }
    numOfBoys = boys;
    beginPos = begin;
    interval = m;}
void Josephus::GetWinner()
{    Ring r1(numOfBoys); //创建n个成员的循环链表
    r1.set_begin(beginPos); //指定从哪个结点开始计数
    r1.print_left(); //打印一下环链
    while(r1.left() > 1) //循环链表中剩下的结点
    {
       r1.kick(interval);   //删除数到的结点
       r1.print_kicked();  //打印刚才删除的结点编号
       r1.print_left();       //打印剩下的链表
       cout << "("<<r1.left() << ")" << endl; //打印一下剩余结点个数
    }
    cout << "Winner is ";    r1.print_left();}
