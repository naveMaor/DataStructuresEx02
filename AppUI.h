//
// Created by Nave on 29/04/2022.
//

#ifndef DATASTRUCTURESEX02_APPUI_H
#define DATASTRUCTURESEX02_APPUI_H


#include "Person.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

using namespace std;

class AppUI {
private:
    int n;
    Person* personArr;
    int k;
    int index=0;

    void GetInput();

public:
    void Run();
    void Print();
};


#endif DATASTRUCTURESEX02_APPUI_H
