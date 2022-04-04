#include "Menu.h"

void IMenu::print_menu(){
    system("clear");
    cout << "Выберите действие:" << endl;
    cout << "1) Прогуляться по зоопарку" << endl;
    cout << "2) Добавить клетку" << endl;
    cout << "3) Поместить животное в клетку" << endl;
    cout << "4) Убрать животное из клетки" << endl;
    cout << "5) Убрать клетку" << endl;
    cout << ">";
}

void IMenu::walkInZoo(){
    for(int i = 0; i < zoo->size(); i++){
        cout << i << " \e[01;38;05;222m В клетке \e[0m" << ": " << zoo->getCage(i) << endl;
    }
}

void IMenu::addCage(){
    zoo->add();
    cout << "\e[01;38;05;107mНовая клетка создана\e[0m" << endl;
}

void IMenu::addAnimalToCage(){
    int cage;
    cout << "Список существующих клеток: " << endl;
    walkInZoo();
    cout << "В какую клетку вы хотите посадить животное" << endl;
    cin >> cage;

//    Cage cage = zoo->getCage(n);
    int leftOrRight;
    cout << "В какую часть клетки выхотите посадить животное" << endl;
    cout << "1) Левую" << endl;
    cout << "2) Правую" << endl;
    cout << ">";
    cin >> leftOrRight;

    int animalId;
    cout << "Какого животного вы хотите посадить?" << endl;
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

//    cage.setAnimal(animal, n);
    try{
        zoo->setAnimalInCage(animal, cage, leftOrRight);
    }
    catch (IException* e){
        e->show();
        delete e;
    }
//    zoo->setAnimalInCage(animal, cage, leftOrRight);
}

void IMenu::removeAnimalFromCage(){
    int n;
    cout << "Из какой клетки вы хотите убрать животное" << endl;
    cin >> n;

    Cage& cage = zoo->getCage(n);
    cout << "Из какой части клетки выхотите убрать животное" << endl;
    cout << "1) Левую" << endl;
    cout << "2) Правую" << endl;
    cout << ">";
    cin >> n;

    cage.setAnimal(nullptr, n);
}

void IMenu::removeCage(){
    cout << "\e[01;38;05;107mТехнические шоколадки:)\e[0m" << endl;
    cout << "\e[01;38;05;107mФункция в разработке\e[0m" << endl;
}
