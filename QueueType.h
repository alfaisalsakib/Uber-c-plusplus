#ifndef QUEUETYPE_H
#define QUEUETYPE_H

#include <iostream>

using namespace std;

class FullQueue {};
class EmptyQueue {};

template <class ItemType>
class QueueType
{
private:
    int front;
    int rear;
    ItemType* items;
    int maxQue;
public:
    QueueType();
    QueueType(int max);
    ~QueueType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Enqueue(ItemType newItem);
    void Dequeue(ItemType& item);
    void PrintQueue();
    ItemType Rear();
};

#endif // QUEUETYPE_H
#include "QueueType.cpp"
