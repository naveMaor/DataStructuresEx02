//
// Created by Nave on 30/04/2022.
//

#ifndef DATASTRUCTURESEX02_MINHEAP_H
#define DATASTRUCTURESEX02_MINHEAP_H


#include "Pair.h"

class MinHeap {

private:
    int maxSize;
    int heapSize;
    bool isAllocated;
    Pair* data;

    void FixHeap(int node,int &NumComp);
    //void FixHeapUp(int node);
    void buildHeap(Pair arr[], int n,int &NumComp);
    //int FindMin(int n1, int n2, int n3);
    void Swap(int i1, int i2);
public:
    int Left(int node);
    int Right(int node);
    int Parent(int node);

    //int Insert(Pair item) ;
    //Pair Delete(int node);
    int getHeapSize() const{
        return heapSize;
    }

public:
    //MinHeap(int max);
    MinHeap(Pair arr[], int n,int &NumComp);
    ~MinHeap();
    Pair Min();
    Pair DeleteMin(int &NumComp);
    bool IsEmpty();

};


#endif DATASTRUCTURESEX02_MINHEAP_H
