#ifndef LOCATIONTYPE_H
#define LOCATIONTYPE_H

#include <iostream>
#include "QueueType.h"

using namespace std;

template <class VertexType>
class LocationType
{
private:
    int numVertices;
    int maxVertices;
    VertexType* vertices;
    int edges[50][50];
public:
    LocationType();
    LocationType(int maxV);
    ~LocationType();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void AddVertex(VertexType );
    void AddEdge(VertexType , VertexType, int );
    int GetWeight(VertexType, VertexType );
    void GetToVertices(VertexType, QueueType<VertexType> &);
    void GetFromVertices(VertexType,  QueueType<VertexType> &);
    bool IsEdge(VertexType from,VertexType to);
    void FloydWarshal();
};

#endif // LOCATIONTYPE_H

#include "LocationType.cpp"
#include "QueueType.cpp"
