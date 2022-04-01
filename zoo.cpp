#include "Zoo.h"

ostream& operator<<(ostream& os, const Cage &cage)
{
    cout << "cage.animal" << endl;
    if (cage.animal1 != nullptr)
    {
        os << "\e[01;38;05;107mЖивотное:\e[0m " << cage.animal1->getName() << " | \e[01;38;05;107mГолос:\e[0m " << cage.animal1->getVoice()
           << " | \e[01;38;05;107mВид:\e[0m " << cage.animal1->getType() << endl;
    }
    if (cage.animal2 != nullptr)
    {
        os << "\e[01;38;05;107mЖивотное:\e[0m " << cage.animal2->getName() << " | \e[01;38;05;107mГолос:\e[0m " << cage.animal2->getVoice()
           << " | \e[01;38;05;107mВид:\e[0m " << cage.animal2->getType() << endl;
    }
    else{
        os << "Error" << endl;
    }
    return os;
}