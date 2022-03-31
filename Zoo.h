#pragma once

#include "Animal.h"
using namespace std;

class Cage{
    Animal *animal;
public:
    Cage(){
        animal = nullptr;
    }
    Cage(Animal *_animal): animal(_animal){
        cout << "Create Cage " << this << endl;
    }
    Cage(const Cage &cageCopy){
        this->animal = cageCopy.animal;
        cout << "Copy Cage " << this << endl;
    }

    ~Cage(){
        cout << "Delete Cage " << this << endl;
        if (animal != nullptr) {
            cout << "Delete Animal " << animal << endl;
//            delete animal;
        }
    }
    int check(){
        if (animal == nullptr) return 0;
        return 1;
    }

    Animal* getAnimal(){
        return animal;
    }

    void setAnimal(Animal *p){
        if(p == nullptr)
            animal = nullptr;
        else{
            animal = p->Clone();
//            cout << p->getName() << " Animal = " << animal << " Cage = " << this << " P = " << p << endl;
//        cout << animal->getType();
//            cout << "Set Animal p(" << p->getName() << ") -> this(" << animal->getName() << ")" << endl;
        }
//        cout << p->getName() << " Animal = " << animal << " Cage = " << this << " P = " << p << endl;
    }

    friend ostream& operator<<(ostream& os, const Cage& dt);
};

class Zoo{
    Cage *list;
    int n;
public:
    Zoo(){
        list = new Cage[0];
        n = 0;
        cout << "Create Zoo " << this << endl;
    }
    ~Zoo(){
        cout << "Delete Zoo" << this << endl;
        delete[] list;
    }

    void add(const Cage &cage){
        cout << "Add new to Zoo ------------" << endl;
        Cage *newCageList = new Cage[n];
        for(int i = 0; i < n; i++){
            newCageList[i].setAnimal(list[i].getAnimal());
//            newCageList[i] = list[i];
            cout << "tmp = " << &newCageList[i] << " anim = " << newCageList[i].getAnimal()  << " <- " << " original = " << &list[i] << " anim = " << list[i].getAnimal() << endl;
//            delete &list[i];
        }
        delete[] list;
        list = new Cage[n+1];
        cout << "CageList: " << endl;
        for(int i = 0; i < n; i++){
//            list[i] = newCageList[i];
            list[i].setAnimal(newCageList[i].getAnimal());
            cout << "tmp = " << &newCageList[i] << " anim = " << newCageList[i].getAnimal()  << " -> " << " original = " << &list[i] << " anim = " << list[i].getAnimal() << endl;
        }
        delete[] newCageList;
        list[n] = cage;
        n++;
        for(int i = 0; i < n; i++){
            cout << i << " " << &list[i] << endl;
        }
    }

    Cage& getCage(int id){
        return list[id];
    }
};
