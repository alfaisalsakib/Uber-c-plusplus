#ifndef SORTEDTYPE_CPP
#define SORTEDTYPE_CPP

#include "SortedType.h"

template <class ItemType>
SortedType<ItemType>::SortedType(int length)
{
    Length = 0;
    MaxLength = length;
    info = new ItemType[MaxLength];
}

template <class ItemType>
SortedType<ItemType>::~SortedType()
{
    delete[] info;
}

template <class ItemType>
bool SortedType<ItemType>::IsFull() const
{
    if(Length == MaxLength)
        return true;
}

template <class ItemType>
int SortedType<ItemType>::GetLength() const
{
    return Length;
}

template <class ItemType>
void SortedType<ItemType>::PutItem(VarType<ItemType> item)
{
    bool moreToSearch;
    int location = 0 ;
    moreToSearch=(location<Length);

    VarType<ItemType> vt;

    while(moreToSearch)
    {
        vt.Initialize(info[location]);

        switch(vt.ComparedTo(item))
        {
        case EQUAL:
        case LESS:
            moreToSearch = false;
            break;
        case GREATER:
            location++;
            moreToSearch = (location<Length);
            break;

        }
     }

     for(int index=Length; index>location; index--)
     {
         info[index] = info[index-1];
     }

     info[location] = item.GetValue();
     Length++;
}

template <class ItemType>
ItemType* SortedType<ItemType>::GetInfo()
{
    return info;
}

template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
{
    Length = 0;
}

template <class ItemType>
void SortedType<ItemType>::ResetList()
{
    currentPos = -1;
}
template <class ItemType>
ItemType SortedType<ItemType>::GetNextItem()
{
    currentPos++;
    return info[currentPos];
}

#endif // SORTEDTYPE_CPP
