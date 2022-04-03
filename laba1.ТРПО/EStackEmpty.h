#ifndef ESTACKEMPTY_H
#define ESTACKEMPTY_H
#include "EStackException.h"
#include <iostream>

class EStackEmpty:public EStackException//наследование
{
public:

    EStackEmpty():EStackException("Stack is empty")// делаем стандартный конструктор
    {

    }
    EStackEmpty(const EStackEmpty &arg):EStackException(arg)
    {

    }

};
#endif // ESTACKEMPTY_H

