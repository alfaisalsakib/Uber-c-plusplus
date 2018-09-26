#ifndef LOCATIONTYPE_CPP
#define LOCATIONTYPE_CPP

#include "LocationType.h"

const int NULL_EDGE = 0;

template <class VertexType>
LocationType<VertexType>::LocationType()
{
    numVertices =0;
    maxVertices = 50;
    vertices = new VertexType[50];
}

template <class VertexType>
LocationType<VertexType>::LocationType(int maxV)
{
    numVertices = 0;
    maxVertices = maxV;
    vertices = new VertexType[maxV];
}

template <class VertexType>
LocationType<VertexType>::~LocationType()
{
    delete[] vertices;
}

template <class VertexType>
void LocationType<VertexType>::AddVertex(VertexType vertex)
{
    vertices[numVertices] = vertex;
    for(int index = 0;index < numVertices; index++)
    {
        edges[numVertices][index] = NULL_EDGE;
        edges[index][numVertices] = NULL_EDGE;
    }

    numVertices++;
}

template <class VertexType>
int IndexIs(VertexType* vertices,VertexType vertex)
{
    int index = 0;
    while(!(vertex == vertices[index]))
        index++;
    return index;
}

template <class VertexType>
void LocationType<VertexType>::AddEdge(VertexType fromVertex,VertexType toVertex,int weight)
{
    int row,col;
    row = IndexIs(vertices,fromVertex);
    col = IndexIs(vertices,toVertex);
    edges[row][col] = weight;
}

template <class VertexType>
int LocationType<VertexType>::GetWeight(VertexType fromVertex,VertexType toVertex)
{
    int row,col;
    row = IndexIs(vertices,fromVertex);
    col = IndexIs(vertices,toVertex);

    return edges[row][col];
}

template <class VertexType>
void LocationType<VertexType>::GetToVertices(VertexType vertex, QueueType<VertexType> &adjVertices)
{
    int fromIndex,toIndex;
    fromIndex = IndexIs(vertices,vertex);
    for(toIndex = 0;toIndex<numVertices;toIndex++)
    {
        if(edges[fromIndex][toIndex] != NULL_EDGE)
            adjVertices.Enqueue(vertices[toIndex]);
    }
}

template <class VertexType>
void LocationType<VertexType>::GetFromVertices(VertexType vertex,  QueueType<VertexType> &adjVertices)
{
    int fromIndex,toIndex;
    fromIndex = IndexIs(vertices,vertex);
    for(toIndex = 0;toIndex<numVertices;toIndex++)
    {
        if(edges[toIndex][fromIndex] != NULL_EDGE)
            adjVertices.Enqueue(vertices[toIndex]);
    }
}

template <class VertexType>
bool LocationType<VertexType>::IsEdge(VertexType from,VertexType to)
{
    int f = IndexIs(vertices,from);
    int t = IndexIs(vertices,to);

    if(edges[f][t] == NULL_EDGE)
        return false;
    else
        return true;
}

template <class VertexType>
void LocationType<VertexType>::FloydWarshal()
{
    string c = "Uttara";
    string d = "Ajimpur";

    for(int k=0;k<8;k++)
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
            {
                if((edges[i][k] * edges[k][j] != 0) && (i!=j))
                {
                    if(edges[i][k]+edges[k][j]<edges[i][j] || edges[i][j]==0)
                    {
                        edges[i][j] = edges[i][k] + edges[k][j];
                        if(vertices[i]==c&&vertices[j]==d)
                        {
                            cout<<vertices[i]<<" "<<vertices[k]<<" "<<edges[i][k]<<endl;
                            cout<<vertices[k]<<" "<<vertices[j]<<" "<<edges[k][j]<<endl;
                            cout<<vertices[i]<<" "<<vertices[j]<<" "<<edges[i][j]<<endl;
                        }
                    }
                }
            }
/*


    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            cout<<vertices[i]<<" "<<vertices[j]<<" ";
            cout<<edges[i][j]<<"  "<<endl;
            /*if(vertices[i] == c && vertices[j] == d)
            {
                cout<<vertices[j]<<"  "<<vertices[i]<<" ";
                cout<<edges[i][j]<<"  "<<endl;
            }
            else
                cout<<vertices[i]<<"  "<<vertices[j]<<" "<<edges[i][j]<<endl;

        }
        cout<<endl;
    }*/
}

#endif // LOCATIONTYPE_CPP
