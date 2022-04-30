//
// Created by Nave on 29/04/2022.
//

#include "AppUI.h"

void AppUI::GetInput() {
    string tmp,name;
    int id;
    getline (std::cin,tmp);
    n = stoi(tmp);
    if(n<0){
        //todo:add exception
        cout << "invalid input" << endl;
        exit(1);
    }
    Person* newPersonArr = new Person[n];
    for (int i = 0; i < n; ++i) {
        std::getline (std::cin,tmp);
        stringstream ss(tmp);
        getline(ss,tmp,' ');
        id = stoi(tmp);
        getline(ss,name);
        for (int j = 0; j < index; ++j) {
            if(newPersonArr[index].getId() == id || newPersonArr[index].getName() == name ){
                //todo:add exception
                cout << "invalid input" << endl;
                exit(1);
            }
        }
        Person newPerson = Person(id,name);
        newPersonArr[index]=newPerson;
        index++;
    }
    personArr = newPersonArr;
    getline (std::cin,tmp);
    k = stoi(tmp);
    if(k<1 || k >n){
        //todo:add exception
        cout << "invalid input" << endl;
        exit(1);
    }


}

void AppUI::Print() {
    cout << "here is the output: "<< endl << endl;
    for (int i = 0; i < n; ++i) {
        cout << "id: " << personArr[i].getId() << " name: " << personArr[i].getName() << endl;
    }
}

void AppUI::Run() {
    GetInput();
    Print();
}
