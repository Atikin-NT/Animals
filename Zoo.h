#pragma once

#include "Animal.h"
#include "IException.h"
#include "Cage.h"
using namespace std;

class Zoo{
    Cage* list;
    int n;
public:
   Zoo(): list(nullptr), n(0){}
   ~Zoo(){
       delete[] list;
   }

   void add();
   int size() const;
   Cage& getCage(int id);
   void setAnimalInCage(Animal* animal, int idCage, int a);
};