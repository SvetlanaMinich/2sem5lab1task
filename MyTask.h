#pragma  once
#ifndef QUEUE_MYTASK_H
#define QUEUE_MYTASK_H
#include <random>
#include "Queue.cpp"

class MyTask
{
private:
    Queue<int> a;
    Queue<int> b;
public:
    MyTask();
    Queue<int> getA();
    Queue<int> getB();
    Queue<int> FindAndInsert();
};


#endif //QUEUE_MYTASK_H
