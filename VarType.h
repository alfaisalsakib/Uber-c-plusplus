#ifndef VARTYPE_H
#define VARTYPE_H

#include <iostream>
using namespace std;

enum RelationType{LESS,GREATER,EQUAL};

template <class ItemType>
class VarType
{
private:
    ItemType value;
public:
    VarType();
    RelationType ComparedTo(VarType ) const;
    void Initialize(ItemType );
    ItemType GetValue();
};

#endif // VARTYPE_H
