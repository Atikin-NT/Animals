#include <iostream>
#include "Zoo.h"
#include "Menu.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "ru");

    IMenu menu = IMenu(new Zoo());

    int n, tmp;
    do {
        menu.print_menu();
        cin >> n;
        cout << endl;
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
            default:{
                n = 0;
            }
        }
//        if(n != 0){
//            cin >> tmp;
//        }
        cout << endl;
    }while(n != 0);
    return 0;
}


// теперь неограниченное число животных в клетке
// если нельзя посадить в клетку, то купить клетку и туда посадить
