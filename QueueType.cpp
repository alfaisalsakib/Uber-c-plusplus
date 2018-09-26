#ifndef QUEUETYPE_CPP
#define QUEUETYPE_CPP

#include "QueueType.h"

template <class ItemType>
QueueType<ItemType>::QueueType()
{
    maxQue= 501;
    front = maxQue-1;
    rear = maxQue-1;
    items = new ItemType[maxQue];
}

template <class ItemType>
QueueType<ItemType>::QueueType(int max)
{
    maxQue= max + 1;
    front = maxQue-1;
    rear = maxQue-1;
    items = new ItemType[maxQue];
}

template <class ItemType>
QueueType<ItemType>::~QueueType()
{
    delete[] items;
}

template <class ItemType>
void QueueType<ItemType>::MakeEmpty()
{
    front = maxQue -1;
    rear = maxQue -1;
}

template <class ItemType>
bool QueueType<ItemType>::IsEmpty()
{
    return (rear == front);
}

template <class ItemType>
bool QueueType<ItemType>::IsFull()
{
    return ((rear+1)%maxQue == front);
}

template <class ItemType>
void QueueType<ItemType>::Enqueue(ItemType newItem)
{
    if (IsFull())
        throw FullQueue();
    else
    {
        rear = (rear +1) % maxQue;
        items[rear] = newItem;
    }
}

template <class ItemType>
void QueueType<ItemType>::Dequeue(ItemType& item)
{
    if (IsEmpty())
        throw EmptyQueue();
    else
    {
        front = (front + 1) % maxQue;
        item = items[front];
    }
}

template<class ItemType>
void QueueType<ItemType>::PrintQueue()
{
    for(int i=(front+1)%maxQue; i!= (rear + 1); i=(i+1)%maxQue)
          cout<<items[i]<<""<<endl;


}
template <class ItemType>
ItemType QueueType<ItemType>::Rear()
{
    return items[rear];
}

#endif // QUEUETYPE_CPP
