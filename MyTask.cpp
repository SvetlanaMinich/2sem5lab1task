#include "MyTask.h"

MyTask::MyTask()
{
    // Создание генератора случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    // Создание распределения
    std::uniform_int_distribution<> dis(1,200);
    for(int i=0;i<10;i++)
    {
        a.push(dis(gen));
        b.push(dis(gen));
    }
}

Queue<int> MyTask::getA()
{
    return a;
}

Queue<int> MyTask::getB()
{
    return b;
}

Queue<int> MyTask::FindAndInsert()
{
    int maxElement = a.front();
    Queue<int> buf;
    while(!a.empty())
    {
        int element = a.front();
        a.pop();
        if(element>maxElement)
        {
            maxElement=element;
        }
        buf.push(element);
    }
    int bufElement = buf.front();
    do
    {
        bufElement = buf.front();
        buf.pop();
        a.push(bufElement);
    } while(bufElement!=maxElement);
    while(!b.empty())
    {
        int aga = b.front();
        b.pop();
        a.push(aga);
    }
    while(!buf.empty())
    {
        int abba = buf.front();
        buf.pop();
        a.push(abba);
    }
    return a;
}










