//
// Created by Nave on 30/04/2022.
//

#ifndef DATASTRUCTURESEX02_RANDSELECTION_H
#define DATASTRUCTURESEX02_RANDSELECTION_H


#include "Func.h"

class RandSelection : public Func{
public:
    string GetName() override{return "RandSelection: ";};
    const Person& RunFunc(Person [] ,int n, int k, int &NumComp) override;

private:
    const Person & select(Person * personArr, int left, int right, int k, int &NumComp);
    int partition(Person *arr, int left, int right, int &NumComp);

};


#endif DATASTRUCTURESEX02_RANDSELECTION_H
