#pragma once

#include "Animal.h"
#include <vector>
using namespace std;

class Cage{
    Animal *animal1;
    Animal *animal2;
public:
    Cage(Animal *_animal1 = nullptr, Animal *_animal2 = nullptr): animal1(_animal1), animal2(_animal2){
        cout << "Create Cage " << this << endl;
    }
    ~Cage(){
        cout << "Delete Cage " << this << endl;
//        delete animal1;
//        delete animal2;
    }

    Animal* getAnimal(int a){
        switch(a){
            case 1: return animal1;
            case 2: return animal2;
            default: return nullptr;
        }
    }

    void setAnimal(Animal* _animal, int a){
        cout << "setAnimalFun " << _animal << " a = " << a << endl;
        switch(a){
            case 1: {animal1 = _animal;
            cout << "Set to animal1 " << animal1 << endl;
            break;}
            case 2: {animal2 = _animal;
                cout << "Set to animal2 " << animal2 << endl;break;}
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
       cout << "Add---------------" << endl;
       Cage* tmp = new Cage[n+1];
       for (int i = 0; i < n; i++) {
//           tmp[i] = list[i].getAnimal(1);
           tmp[i].setAnimal(list[i].getAnimal(1), 1);
           cout << &tmp[i] << " animal = " << tmp[i].getAnimal(1) << " <- " << &list[i] << " animal = " << list[i].getAnimal(1) << endl;
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