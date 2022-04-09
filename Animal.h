#pragma once
#include <iostream>
#include <string>
using namespace std;

class Animal{
public:
    virtual bool getType() = 0;
    virtual string getName() = 0;
    virtual string getVoice() = 0;

    Animal(){
//        cout << "Create Animal " << this << endl;
    }

    ~Animal(){
//        cout << "Delete Animal " << this << endl;
    }
};

class Herbivore: public Animal{
public:
    bool getType() override { return false; }
};

class Predator: public Animal{
public:
    bool getType() override { return true; }
};

class Rabbit: public Herbivore{
public:
    string getName() override { return "Заяц"; }
    string getVoice() override { return "Фрфрфрфр"; }
};

class Hohotun: public Herbivore{
public:
    string getName() override { return "Древесный хохотун"; }
    string getVoice() override { return "Хохо"; }
};

class Ferret: public Predator{
public:
    string getName() override { return "Хорёк-паникёр"; }
    string getVoice() override { return "ЪУЪ!"; }
};

class Grasshopper: public Predator{
public:
    string getName() override { return "Гигантский саблезубый кузнечик"; }
    string getVoice() override { return "Скырк-скырк"; }
};

class FlyBear: public Predator{
public:
    string getName() override { return "Медведь-летун"; }
    string getVoice() override { return "Курлык-Курдык"; }
};