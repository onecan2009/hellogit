#ifndef _JOSEPHUS_H_
#define _JOSEPHUS_H_
class Josephus{
public:
    Josephus(int boys=0, int begin=0, int m=0);
    void GetWinner();
protected:
    int numOfBoys;
    int beginPos;
    int interval;
};
#endif
