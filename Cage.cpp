#include "Cage.h"


Animal* Cage::getAnimal(int a){
    switch(a){
        case 1: return animal1;
        case 2: return animal2;
        default: return nullptr;
    }
}

bool Cage::SetAndCheckAnimal(Animal *_animal1, Animal *_animal2){
    if(_animal2 != nullptr && _animal1 != nullptr){
        if((_animal1->getType() && !_animal2->getType()) || (!_animal1->getType() && _animal2->getType())){
            throw new IntEx(1);
        }
        if(_animal1->getType() && _animal2->getType()){
            throw new IntEx(2);
        }
    }
    return true;
}

void Cage::setAnimal(Animal* _animal, int a){
    switch(a){
        case 1: {
            try {
                if(SetAndCheckAnimal(_animal, animal2)){
                    delete animal1;
                    animal1 = _animal;
                }
            }
            catch (IException* e){
                e->show();
                delete e;
                delete _animal;
            }
            break;
        }
        case 2: {
            try {
                if(SetAndCheckAnimal(_animal, animal1)){
                    delete animal2;
                    animal2 = _animal;
                }
            }
            catch (IException* e){
                e->show();
                delete e;
                delete _animal;
            }
            break;
        }
        default:;
    }
}

ostream& operator<<(ostream& os, const Cage &cage)
{
    if (cage.animal1 != nullptr)
    {
        os << "\e[01;38;05;107mЖивотное 1:\e[0m " << cage.animal1->getName() << " | \e[01;38;05;107mГолос:\e[0m " << cage.animal1->getVoice()
           << " | \e[01;38;05;107mВид:\e[0m " << cage.animal1->getType() << "     ";
    }
    else{
        os << "\e[01;38;05;107mЖивотное 1:\e[0m " << "Пусто ";
    }
    if (cage.animal2 != nullptr)
    {
        os << "\e[01;38;05;107mЖивотное 2:\e[0m " << cage.animal2->getName() << " | \e[01;38;05;107mГолос:\e[0m " << cage.animal2->getVoice()
           << " | \e[01;38;05;107mВид:\e[0m " << cage.animal2->getType() << "     ";
    }
    else{
        os << "\e[01;38;05;107mЖивотное 2:\e[0m " << "Пусто ";
    }
    return os;
}