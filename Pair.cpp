//
// Created by Nave on 30/04/2022.
//

#include "Pair.h"

int Pair::getPriority() const {
    return priority;
}

void Pair::setPriority(int priority) {
    this->priority = priority;
}


/*Pair::Pair(Edge* data) {

    this->data = data;
    this->priority = data->getWeight();
}*/

Pair::Pair(){}

Pair::Pair(string data, int priority)
{
    this->data = data;
    this->priority = priority;
}

/*Pair::Pair(Edge* data, int priority)
{
    this->data = data;
    this->priority = priority;
}*/


string Pair::getData() {
    return data;
}

void Pair::setData(string data) {
    Pair::data = data;
}