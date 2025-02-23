#include "intcell.h"

IntCell::IntCell(int value){
    this->value=value;
}

int IntCell::read() const
{
    return value;
}

void IntCell::write(int x){
    value=x;
}