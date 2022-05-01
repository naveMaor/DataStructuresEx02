//
// Created by Nave on 30/04/2022.
//


#include "MinHeap.h"
#include "HeapException.h"

int MinHeap::Left(int node)
{
    return 2 * node + 1;
}

int MinHeap::Right(int node)
{
    return 2 * node + 2;
}

int MinHeap::Parent(int node)
{
    return  (node - 1) / 2;
}

/*MinHeap::MinHeap(int max)
{
    data = new Pair[max];
    maxSize = max;
    heapSize = 0;
    isAllocated = true;
}*/

MinHeap::~MinHeap()
{
    if(isAllocated)
        delete [] data;
    data = nullptr;
}

/*Pair MinHeap::Delete(int node)
{
    if(heapSize < 1)
        throw HeapException("no nodes in the heap");
    Pair temp = data[node];
    heapSize--;
    data[node] = data[heapSize];
    if(FindMin(data[node].getPriority(), data[ 2 * node + 1].getPriority(),
               data[2 * node + 2].getPriority()) != data[node].getPriority())
    {
        FixHeap(node);
    }
    else{
        FixHeapUp(node);
    }

    return temp;
}*/

/*int MinHeap::FindMin(int n1, int n2, int n3)
{
    int min = n1 < n2 ? n1 : n2;
    min = min < n3 ? min : n3;

    return min;
}*/

/*int MinHeap::getHeapSize() const {
    return heapSize;
}*/

void MinHeap::FixHeap(int node,int &NumComp)
{
    int min;
    int left = Left(node);
    int right = Right(node);
    NumComp= NumComp+2;
    if((left < heapSize) && (data[left].getPriority() < data[node].getPriority()))
        min = left;
    else
        min = node;
    NumComp= NumComp+2;
    if (( right < heapSize) && (data[right].getPriority() < data[min].getPriority()))
        min = right;

    if(min != node)
    {
        //TODO: check if ok
        Swap(node, min);
        FixHeap(min,NumComp);
    }
}

void MinHeap::Swap(int i1, int i2)
{
    Pair temp = data[i1];
    data[i1] = data[i2];
    data[i2] = temp;
}

Pair MinHeap::Min()
{
    return data[0];
}

Pair MinHeap::DeleteMin(int &NumComp)
{
    if(heapSize < 1)
        throw HeapException("no nodes in the heap");
    Pair min = data[0];
    heapSize--;
    data[0] = data[heapSize];
    FixHeap(0,NumComp);
    return min;
}

/*int MinHeap::Insert(Pair item)
{
    if(heapSize == maxSize)
        throw HeapException("no more space in the heap");
    int i = heapSize;
    heapSize++;
    while( ( i > 0 ) && (data[Parent(i)].getPriority() > item.getPriority()))
    {
        data[i] = data[Parent(i)];
        i = Parent(i);
    }
    data[i] = item;

    return i;
}

void MinHeap::FixHeapUp(int node)
{//I am bigger than my elementsArr

    int parent = Parent(node);

    while(node != 0 && data[node].getPriority() < data [parent].getPriority())
    {
        Swap(node, parent);
        node = parent;
        parent = Parent(node);
    }
}*/

bool MinHeap::IsEmpty() {
    return this->heapSize == 0;
}

void MinHeap::buildHeap(Pair *arr, int n,int &NumComp) {

    int startIdx = (n / 2) - 1;

    for (int i = startIdx; i >= 0; i--) {
        this->FixHeap(i,NumComp);
    }
}

MinHeap::MinHeap(Pair *arr, int n,int &NumComp) {

    this->data = arr;
    this->heapSize = n;
    this->maxSize = n;
    this->isAllocated = false;
    buildHeap(arr, n,NumComp);
}





