#pragma once

#include "Animal.h"
#include "IException.h"
#include <vector>
using namespace std;

class Cage{
    Animal *animal1;
    Animal *animal2;
public:
    Cage(Animal *_animal1 = nullptr, Animal *_animal2 = nullptr): animal1(_animal1), animal2(_animal2){}
    ~Cage(){}

    Animal* getAnimal(int a){
        switch(a){
            case 1: return animal1;
            case 2: return animal2;
            default: return nullptr;
        }
    }

    Animal* setChekSetAnimal(Animal *_animal1, Animal *_animal2){
        if(_animal2 != nullptr && _animal1 != nullptr){
            if((_animal1->getType() && !_animal2->getType()) || (!_animal1->getType() && _animal2->getType())){
                throw new IntEx(1);
            }
            if(_animal1->getType() && _animal2->getType()){
                throw new IntEx(2);
            }
        }
        return _animal1;
    }

    void setAnimal(Animal* _animal, int a){
        switch(a){
            case 1: {
                try {
//                    animal1 = _animal;
                    animal1 = setChekSetAnimal(_animal, animal2);
                }
                catch (IException* e){
                    e->show();
                }
                break;
            }
            case 2: {
                try {
//                    ChekSetAnimal(_animal, animal1);
//                    animal2 = _animal;
                    animal2 = setChekSetAnimal(_animal, animal1);
                }
                catch (IException* e){
                    e->show();
                }
                break;
            }
            default:;
        }
    }

    friend ostream& operator<<(ostream& os, const Cage& dt);
};

class Zoo{
    Cage* list;
    int n;
public:
   Zoo(): list(nullptr), n(0){}
   ~Zoo(){
       delete[] list;
   }
   void add(){
       Cage* tmp = new Cage[n+1];
       for (int i = 0; i < n; i++) {
           tmp[i].setAnimal(list[i].getAnimal(1), 1);
       }
       delete[] list;
       list = tmp;
       n++;
   }

   int size() const{
       return n;
   }
   Cage& getCage(int id){
       return list[id];
   }

};