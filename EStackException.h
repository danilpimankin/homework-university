#ifndef STACKEXCEPTION_H
#define STACKEXCEPTION_H
#include<cstring>

class EStackException
{
private: char *message;
   public:
    EStackException(const char *arg_message)// делаем конструктор
    {
        message=new char[strlen(arg_message)+1];//просто выделяем память
        strcpy(message,arg_message);
    }
    EStackException(const EStackException &arg)//тут мы копируем
    {
        message=new char[strlen(arg.message)+1];//снова выделяем память
         strcpy(message,arg.message);

    }
    ~EStackException()
    {
        delete message;
    }
};

#endif
