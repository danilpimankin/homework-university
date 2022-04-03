#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include <QString>
#include <QRegularExpression>
using namespace std;

class Person
{
public:
    QString firstName;
    QString lastName;
    QString patronymic;
public:
    Person();//конструктор
    Person(QString fullName);//конструтор одной строки
    Person(const Employee&);
    void setFirstName(QString _firstName);
    void setLastName(QString _lastName);
    void setPatronymic(QString _patronymic);
    const QString& getFirstName() const { return firstName; }
    const QString& getLastName() const { return lastName; }
    const QString& getPatronymic() const { return patronymic; }

};
#endif
