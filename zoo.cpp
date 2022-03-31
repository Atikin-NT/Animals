#include "Zoo.h"

ostream& operator<<(ostream& os, const Cage &cage)
{
    if (cage.animal != nullptr)
    {
        os << "\e[01;38;05;107mЖивотное:\e[0m " << cage.animal->getName() << " | \e[01;38;05;107mГолос:\e[0m " << cage.animal->getVoice()
       << " | \e[01;38;05;107mВид:\e[0m " << cage.animal->getType() << endl;
    }
    else{
        os << "Error" << endl;
    }
    return os;
}

