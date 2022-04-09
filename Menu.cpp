#include "Menu.h"

void IMenu::print_menu(){
//    system("clear");
    cout << "\e[01;38;05;222mВыберите действие:\e[0m" << endl;
    cout << "1) Прогуляться по зоопарку" << endl;
    cout << "2) Добавить клетку" << endl;
    cout << "3) Поместить животное в клетку" << endl;
    cout << ">";
}

void IMenu::walkInZoo(){
    for(int i = 0; i < zoo->size(); i++){
        cout << i << " \e[01;38;05;222m В клетке \e[0m" << ": " << endl;
        zoo->getCage(i).print();
    }
}

void IMenu::addCage(){
    zoo->add();
    cout << "\e[01;38;05;107mНовая клетка создана\e[0m" << endl;
}

void IMenu::addAnimalToCage(){
    int cage;
    cout << "\e[01;38;05;222mСписок существующих клеток: \e[0m" << endl;
    walkInZoo();
    cout << endl << "В какую клетку вы хотите посадить животное" << endl;
    cout << ">";
    cin >> cage;

//    Cage cage = zoo->getCage(n);
    int idAnimal;
    cout << endl <<"В какое место клетки выхотите посадить животное(-1 - добавить в конец)" << endl;
    cout << ">";
    cin >> idAnimal;

    int animalId;
    cout << endl << "Какого животного вы хотите посадить?" << endl;
    cout << "1) Заяц" << endl;
    cout << "2) Древесный хохотун" << endl;
    cout << "3) Хорёк-паникёр" << endl;
    cout << "4) Гигантский саблезубый кузнечик" << endl;
    cout << "5) Медведь-летун" << endl;
    cout << ">";
    cin >> animalId;

    Animal* animal;
    switch(animalId){
        case 1: {animal = new Rabbit(); break;}
        case 2: {animal = new Hohotun(); break;}
        case 3: {animal = new Ferret(); break;}
        case 4: {animal = new Grasshopper(); break;}
        case 5: {animal = new FlyBear(); break;}
        default: {animal = nullptr; break;}
    }
    zoo->setAnimalInCage(animal, cage, idAnimal);
}
