//
// Created by Nave on 30/04/2022.
//

#ifndef DATASTRUCTURESEX02_SELECTHEAP_H
#define DATASTRUCTURESEX02_SELECTHEAP_H
#include "Func.h"
#include "Pair.h"
#include "MinHeap.h"


class selectHeap : public Func{
public:
string GetName() override{return "selectHeap: ";};
const Person& RunFunc(Person [] ,int n, int k, int &NumComp) override;
};


#endif DATASTRUCTURESEX02_SELECTHEAP_H
