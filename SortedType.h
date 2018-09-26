#ifndef SORTEDTYPE_H
#define SORTEDTYPE_H

#include "DriverType.h"
#include "VarType.h"

using namespace std;

template <class ItemType>
class SortedType
{
private:
    int Length;
    int MaxLength;
    int currentPos;
    ItemType* info;
public:
    SortedType(int );
    ~SortedType();
    bool IsFull() const;
    int GetLength() const;
    void PutItem(VarType<ItemType> );
    ItemType* GetInfo();
    void MakeEmpty();
    void ResetList();
    ItemType GetNextItem();
};

#endif // SORTEDTYPE_H
#include "VarType.cpp"
