#pragma once
#include "Animal.h"
#include "IException.h"

class Cage{
    Animal** animalList;
    int n;
//    Animal *animal1;
//    Animal *animal2;
public:
//    Cage(Animal *_animal1 = nullptr, Animal *_animal2 = nullptr): animal1(_animal1), animal2(_animal2){}
    Cage(Animal** _animalList = nullptr, int _n = 0): n(_n){
        if(_animalList == nullptr) animalList = new Animal*[n];
    }
    ~Cage(){
        delete[] animalList;
    }

    void print();

    int size(){ return n; }

    void setAnimal(Animal* _animal, int idAnimal);

    void addPlaceForAnimal();

    friend ostream& operator<<(ostream& os, Cage& dt);

    Cage& operator=(const Cage& right);
};
