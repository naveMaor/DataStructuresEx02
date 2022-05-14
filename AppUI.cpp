//
// Created by Nave on 29/04/2022.
//

#include "AppUI.h"

void AppUI::GetInput() {
    string tmp,name;
    int id,index=0;
    getline (std::cin,tmp);
    n = stoi(tmp);
    if(n<0){
        //todo:add exception
        cout << "invalid input - 1" << endl;
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
            int compareID =newPersonArr[j].getId();
            if(compareID == id){// || newPersonArr[index].getName() == name ){
                //todo:add exception
                cout << "invalid input - 2" << endl;
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
        cout << "invalid input - 3" << endl;
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
    int numberOfComp = 0;

    GetInput();
    //Print();
    Func* funcs[3];
    funcs[0] = new RandSelection();
    funcs[1] = new selectHeap();
    funcs[2] = new BST();
    cout << "\n \n result: "<< endl;
    Person p1;
    for (int i = 0; i < 3; ++i) {
        cout << funcs[i]->GetName() ;
        numberOfComp = 0;
        p1 = funcs[i]->RunFunc(personArr,n,k,numberOfComp);
        cout << p1.getId() << " " << p1.getName() << " " << numberOfComp << " comparisons"  << endl;
    }
}
