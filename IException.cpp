#include "IException.h"

void IntEx::show(){
    switch(a){
        case 1:{
            cout << "\e[01;38;05;196mEx 0: \e[38;05;196mНельзя посадить хищника рядом с травоядным!\e[0m" << endl;
            break;
        }
        case 2:{
            cout << "\e[01;38;05;196mEx 1: \e[38;05;196mНельзя посадить хищника рядом с хищником!\e[0m" << endl;
            break;
        }
        default:{
            cout << "\e[01;38;05;196mНеизвестная ошибка\e[0m" << endl;
            break;
        }
    }
}