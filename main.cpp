#include <iostream>
#include "Animal.h"
#include "Zoo.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

//    Cage animals[12];
//    animals[0] = Cage(Rabbit());
//    animals[1] = Cage(Bear());
//    animals[2] = Cage(Grasshopper());
//    animals[3] = Cage(CrawlOut());
//    animals[4] = Cage(Goat());
//    animals[6] = Cage(FlyBear());
//    animals[8] = Cage(Hohotun());
//    animals[9] = Cage(Ferret());
//    animals[10] = Cage(Wolf());
//    animals[11] = Cage(Fox());
    Zoo zoo;
    zoo.add(Cage(new Goat));
    zoo.add(Cage());
    zoo.add(Cage(new Hohotun));
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
    for(int i = 0; i < 3; i++){
        cout << "\e[01;38;05;222m В клетке \e[0m" << ": " << zoo.getCage(i) << zoo.getCage(i).check() << endl;
    }
    return 0;
}
