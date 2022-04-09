#include "Cage.h"

void Cage::setAnimal(Animal* animal, int idAnimal){
    if (idAnimal < 0 || idAnimal >= n)
        throw new IntEx(3);
    if (animal->getType()){
        for (int i = 0; i < n; i++) {
            if(animalList[i] != nullptr)
                throw new IntEx(1);
        }
    }
    else{
        for (int i = 0; i < n; i++) {
            if(animalList[i] != nullptr && animalList[i]->getType())
                throw new IntEx(2);
        }
    }
    delete animalList[idAnimal];
    animalList[idAnimal] = animal;
}

void Cage::addPlaceForAnimal(){
    Animal** newAnimalList = new Animal*[n+1];
    for (int i = 0; i < n; i++) {
        newAnimalList[i] = animalList[i];
        animalList[i] = nullptr;
    }
    delete animalList;
    animalList = newAnimalList;
    animalList[n] = nullptr;
    n++;
}

ostream& operator<<(ostream& os, Cage &cage)
{
    cout << "Список животных в клетке:" << endl;
    Animal* tmp;
    for (int i = 0; i < cage.n; i++) {
        cout << i << ") ";
        tmp = cage.animalList[i];
        if(tmp != nullptr)
            os << "\e[01;38;05;107mЖивотное:\e[0m " << tmp->getName() << " | \e[01;38;05;107mГолос:\e[0m " << tmp->getVoice()
               << " | \e[01;38;05;107mВид:\e[0m " << tmp->getType() << "     ";
        else
            os << "Пусто";
    }
    return os;
}

void Cage::print(){
    cout << "\t\e[01;38;05;222mСписок животных в клетке:\e[0m" << endl;
    Animal* tmp;
    for (int i = 0; i < n; i++) {
        cout << "\t\t" << i << ") ";
        tmp = animalList[i];
        if(tmp != nullptr)
            cout << "\e[01;38;05;107mЖивотное:\e[0m " << tmp->getName() << " | \e[01;38;05;107mГолос:\e[0m " << tmp->getVoice()
               << " | \e[01;38;05;107mВид:\e[0m " << tmp->getType() << "     ";
        else
            cout << "Пусто";
        cout << endl;
    }
    if(n == 0)
        cout << "\t\tВ клетке пусто";
    cout << endl;
}

Cage& Cage::operator=(const Cage& right) {
    if (this == &right)
        return *this;

    delete[] animalList;
    animalList = new Animal*[right.n];
    n = right.n;
    for (int i = 0; i < right.n; i++) {
        animalList[i] = right.animalList[i];
        right.animalList[i] = nullptr;
    }

    return *this;
}