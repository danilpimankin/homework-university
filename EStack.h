#ifndef ESTACK_H
#define ESTACK_H
#include<iostream>
#include"EStackEmpty.h"
#include <functional>
using namespace std;

template <class T>//шаблонный класс
class EStack
{
    public:
    struct Node//список
    {
        T T_value;//значение
        Node *prev;//указатель на пред.

    };
    Node *root=nullptr;//последний элемент
    int size=0;//просто переменная для размера
    ~EStack();//Деструктор
    void Push(const T &value);//Добавление в стек
    const T Pop();//извлечения из стека
    void Iter(std::function<void(const T &value)> Pip) const ;//Идём по стеку(итерация)
    int Size();//Размер
    void Clear();//Подчищаем за собой

};
template <class T>
void EStack<T>::Push(const T &value)
{
  Node *node=new Node{value,root};
  node->T_value=value;
  node->prev=root;
   if (node==nullptr)//проверка на пустоту
   {
       throw EStackException("Not enough memory.");
   }


   root=node;
   size++;

}
template <class T>
void EStack<T>::Clear()
{
    while (root!=nullptr)//подчищаем
    {
        Node *last=root;//берем крайний элемент
        root=root->prev;
        delete last;//и удаляем его
    }
}
template <class T>
EStack<T>::~EStack()//деструктор
{
    Clear();
}
template <class T>
int EStack<T>::Size()
{
    return size;
}
template <class T>
const T EStack<T>::Pop()
{if (root==nullptr)
    {
        throw EStackEmpty();//поимка исключений
    }
    const T value=root->T_value;
    Node *last =root;
    root=root->prev;
    delete last;
    size--;
    return value;//возвращаем

}
template <class T>
void EStack<T>::Iter(std::function<void(const T &value)> Pip) const
{
    Node *trash = root; //перебираем все элементы, начинаем мы с последнего

        while (trash != nullptr) //пока не дойдём до первого
        {
            Pip(trash->T_value); //вызов callback функции

            trash = trash->prev;
        }
};

#endif // STACK_H
