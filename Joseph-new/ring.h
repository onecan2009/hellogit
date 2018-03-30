#include <stdlib.h>
#include <iostream>
#ifndef _RING_H_
#define _RING_H_
struct nod
{    nod(int n = 0)
    {        id = n;        prior = NULL;        next = NULL;    }
    int id;
    struct nod *prior;
    struct nod *next;
};
class Ring
{public:
    Ring(int n);
    bool set_begin(int n);
    int left() const;
    bool kick(int step);
    void print_kicked();
    void print_left();
private:
    int size;    int kicked;    nod *head;    nod *tail;    nod *begin;
};
#endif
