#include <iostream>
#include "Zoo.h"
#include "Menu.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    IMenu menu = IMenu(new Zoo());

    int n;
    do {
        menu.print_menu();
        cin >> n;
        switch(n){
            case 1:{
                menu.walkInZoo();
                break;
            }
            case 2:{
                menu.addCage();
                break;
            }
            case 3:{
                menu.addAnimalToCage();
                break;
            }
            case 4:{
                menu.removeAnimalFromCage();
                break;
            }
            case 5:{
                menu.removeCage();
                break;
            }
            default:{
                n = 0;
            }
        }
        if(n != 0){
            system("sleep 6");
        }
    }while(n != 0);
    return 0;
}
