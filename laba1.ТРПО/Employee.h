#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
#include <QString>
#include <QRegularExpression>
using namespace std;

class Employee
{
public:
    QString firstName;
    QString lastName;
    QString patronymic;
public:
    Employee();//конструктор
    Employee(QString fullName);//конструтор одной строки
    Employee(const Employee&);
    void setFirstName(QString _firstName);
    void setLastName(QString _lastName);
    void setPatronymic(QString _patronymic);
    const QString& getFirstName() const { return firstName; }
    const QString& getLastName() const { return lastName; }
    const QString& getPatronymic() const { return patronymic; }

};
#endif
