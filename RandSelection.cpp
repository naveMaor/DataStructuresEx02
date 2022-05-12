//
// Created by Nave on 30/04/2022.
//

#include "RandSelection.h"

const Person &RandSelection::select(Person A[], int left, int right, int i, int &NumComp) {
    NumComp++;
    int pivot;
    int leftPart;
    pivot = partition(A, left, right, NumComp);
    leftPart = pivot - left+1;
    if (i==leftPart){
        return A[pivot];
    }
    if(i<leftPart)
        return select(A,left,pivot-1,i,NumComp);
    else
        return select(A,pivot+1,right,i-leftPart,NumComp);


}

int RandSelection::partition(Person *arr, int left, int right, int &NumComp) {
    int start = left;
    int end = right;
    srand(time(nullptr));
    int pivotIndex = left + rand() % (right-left+1);
    swap(arr[left], arr[pivotIndex]);

    int pivot = arr[start].getId();

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i].getId() <= pivot){
            NumComp++;
            count++;
        }
    }

    // Giving pivot element its correct position
    pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i].getId() <= pivot) {
            NumComp++;
            i++;
        }

        while (arr[j].getId() > pivot) {
            NumComp++;
            j--;
        }
        NumComp++;
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;

}


const Person &RandSelection::RunFunc(Person personArr[], int n, int k, int &NumComp) {
    //copy the previous array
    Person * data = new Person[n];
    for (int i = 0; i < n; ++i){
        Person person = Person(personArr[i].getId(),personArr[i].getName());
        data[i]= person;
    }

    Person* result = new Person(select(data,0,n-1,k,NumComp)) ;

    //delete the pointer
    delete [] data;
    return *result;

}
