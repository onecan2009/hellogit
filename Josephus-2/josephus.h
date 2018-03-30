#ifndef _JOSEPHUS_H_
#define _JOSEPHUS_H_
#include "ring.h"
class Josephus{
public:
    Josephus();
    void Input();
    void GetWinner();
    ~Josephus(){delete pRing;}
protected:
    int numOfBoys;
    int beginPos;
    int interval;
    Ring*   pRing;
};
#endif
