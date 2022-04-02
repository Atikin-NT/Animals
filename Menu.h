#pragma once
#include <cstdlib>
#include <iostream>
#include "Zoo.h"

using namespace std;

class IMenu{
    Zoo* zoo;
public:
    IMenu(Zoo *_zoo = nullptr): zoo(_zoo){}

    void print_menu();
    void walkInZoo();
    void addCage();
    void addAnimalToCage();
    void removeAnimalFromCage();
    void removeCage();
};