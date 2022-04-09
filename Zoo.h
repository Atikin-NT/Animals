#pragma once

#include "Animal.h"
#include "IException.h"
#include "Cage.h"
using namespace std;

class Zoo{
    Cage* cageList;
    int n;
public:
   Zoo(): cageList(nullptr), n(0){}
   ~Zoo(){
       delete[] cageList;
   }

   void add();
   int size() const;
   Cage& getCage(int id);
   void setAnimalInCage(Animal* animal, int idCage, int idAnimal);
};