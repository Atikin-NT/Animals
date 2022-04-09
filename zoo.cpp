#include "Zoo.h"
void Zoo::add(){
    Cage* newCageList = new Cage[n+1];
    for (int i = 0; i < n; i++) {
        newCageList[i] = cageList[i];
    }
    delete[] cageList;
    cageList = newCageList;
    n++;
}

int Zoo::size() const{
    return n;
}
Cage& Zoo::getCage(int id){
    return cageList[id];
}

void Zoo::setAnimalInCage(Animal* animal, int idCage, int idAnimal){
    try{
        if(idAnimal == -1) {
            cageList[idCage].addPlaceForAnimal();
            cageList[idCage].setAnimal(animal, cageList[idCage].size() - 1);
        }
        else{
            cageList[idCage].setAnimal(animal, idAnimal);
        }
    }
    catch (IException* e){
        cout << endl;
        e->show();

        cout << "\e[01;38;05;222mЖивотное будет помещено в новую клетку!\e[0m" << endl;
        add();
        cageList[n-1].addPlaceForAnimal();
        cageList[n-1].setAnimal(animal, 0);
        delete e;
    }
}