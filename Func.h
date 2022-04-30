//
// Created by Nave on 30/04/2022.
//

#ifndef DATASTRUCTURESEX02_FUNC_H
#define DATASTRUCTURESEX02_FUNC_H
#include <iostream>
#include "Person.h"

using namespace std;

class Func {
public:
    virtual string GetName() = 0;
    virtual const Person& RunFunc(Person [] ,int n, int k, int &NumComp) = 0;
};


#endif DATASTRUCTURESEX02_FUNC_H
