#ifndef VARTYPE_CPP
#define VARTYPE_CPP

#include "VarType.h"

template <class ItemType>
VarType<ItemType>::VarType()
{

}

template <class ItemType>
RelationType VarType<ItemType>::ComparedTo(VarType otherItem) const
{
    //cout<<otherItem.value<<endl;

    if(value<otherItem.value)
    {
        return LESS;
        //cout<<otherItem.value<<endl;
    }
    else if(value>otherItem.value)
    {
        return GREATER;
        //cout<<value<<endl;
    }
    else
    {
        return EQUAL;
        //cout<<"here"<<endl;
    }
}

template <class ItemType>
void VarType<ItemType>::Initialize(ItemType item)
{
    value = item;
}

template <class ItemType>
ItemType VarType<ItemType>::GetValue()
{
    return value;
}

#endif // VARTYPE_CPP
