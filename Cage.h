#pragma once
#include "Animal.h"
#include "IException.h"

class Cage{
    Animal *animal1;
    Animal *animal2;
public:
    Cage(Animal *_animal1 = nullptr, Animal *_animal2 = nullptr): animal1(_animal1), animal2(_animal2){}
    ~Cage(){}

    Animal* getAnimal(int a);

    bool SetAndCheckAnimal(Animal *_animal1, Animal *_animal2);

    void setAnimal(Animal* _animal, int a);

    friend ostream& operator<<(ostream& os, const Cage& dt);
};
