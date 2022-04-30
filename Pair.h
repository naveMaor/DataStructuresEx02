//
// Created by Nave on 30/04/2022.
//

#ifndef DATASTRUCTURESEX02_PAIR_H
#define DATASTRUCTURESEX02_PAIR_H


#include "iostream"

using namespace std;

class Pair {
private:
    int priority;
    string data;

public:
    //Pair(Edge* data);
    //Pair(Edge* data, int priority);
    Pair(string data, int priority);
    Pair();

    int getPriority() const;
    void setPriority(int priority);
    string getData();
    void setData(string data);


    friend ostream& operator<<(ostream& out, const Pair& p)  {
        return out << p.priority << " " << p.data;
    }
};


#endif DATASTRUCTURESEX02_PAIR_H
