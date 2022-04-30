//
// Created by Nave on 29/04/2022.
//

#ifndef DATASTRUCTURESEX02_PERSON_H
#define DATASTRUCTURESEX02_PERSON_H
#include <string>


class Person {
private:
    int ID;
    std::string name;
public:
    Person(int id, const std::string &name) : ID(id), name(name) {}

    int getId() const {
        return ID;
    }

    const std::string &getName() const {
        return name;
    }

    Person() {

    }
};


#endif DATASTRUCTURESEX02_PERSON_H
