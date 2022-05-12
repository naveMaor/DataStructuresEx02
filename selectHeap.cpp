//
// Created by Nave on 30/04/2022.
//

#include "selectHeap.h"

const Person &selectHeap::RunFunc(Person personArr[], int n, int k, int &NumComp) {
    //copying the previous array to temporary new array
    Pair * data = new Pair[n];
    Pair curr;
    for (int i = 0; i < n; ++i) {
        data[i].setData(personArr[i].getName());
        data[i].setPriority(personArr[i].getId());
    }

    MinHeap selectMinHeap = MinHeap(data,n,NumComp);
    for (int i = 1; i <= k; ++i) {
        curr = selectMinHeap.DeleteMin(NumComp);
    }
    Person *result = new Person(curr.getPriority(),curr.getData());
    delete [] data;
    return *result;
}
