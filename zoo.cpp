#include "Zoo.h"
void Zoo::add(){
    Cage* tmp = new Cage[n+1];
    for (int i = 0; i < n; i++) {
        tmp[i].setAnimal(list[i].getAnimal(1), 1);
    }
    delete[] list;
    list = tmp;
    n++;
}

int Zoo::size() const{
    return n;
}
Cage& Zoo::getCage(int id){
    return list[id];
}

void Zoo::setAnimalInCage(Animal* animal, int idCage, int a){
    if (idCage < 0 || idCage >= n) throw new IntEx(3);

    list[idCage].setAnimal(animal, a);
}