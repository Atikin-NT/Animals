#include <iostream>
#include "Animal.h"
#include "Zoo.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    Zoo zoo;
    zoo.add();
    zoo.add();
    zoo.getCage(0).setAnimal(new Goat(), 1);
    zoo.getCage(1).setAnimal(new Hohotun(), 2);
    zoo.add();
    zoo.getCage(2).setAnimal(new Hohotun(), 1);
//    zoo.add(Cage(new Hohotun));
//    zoo.add(Cage(new Wolf));
//    zoo.add(Cage(new Fox));
//    zoo.add(Cage(new FlyBear));
//    zoo.add(Cage(new Grasshopper));
//    Animal *animal;
//    animal = new Rabbit;
//    Cage cage(animal);
//    cout << cage.check();
//    Animal *animal2 = cage.getAnimal();
//    cout << animal2->getVoice();
    for(int i = 0; i < zoo.size(); i++){
        cout << i << " \e[01;38;05;222m В клетке \e[0m" << ": " << zoo.getCage(i) << endl;
    }
    return 0;
}
