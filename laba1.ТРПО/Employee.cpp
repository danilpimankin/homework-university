#include "Employee.h"

Employee::Employee()//конструктор
{
    firstName = "pip";
    lastName = "piip";
    patronymic = "piiip";
}
Employee::Employee(QString fullName)
{
    QStringList words = fullName.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts); //разбиваем слово на части

        if (words.size() != 2 && words.size() != 3)
        {
            throw "incorrect format";
        }

        lastName = words[0];

        firstName = words[1];


        if (words.size() == 3)
        {
            patronymic = words[2];
        }
}
Employee::Employee(const Employee& employee)
{
    firstName = employee.firstName;
    lastName = employee.lastName;
    patronymic = employee.patronymic;
}

void Employee::setFirstName(QString newFirstName)
{
    firstName = newFirstName;
}
void Employee::setLastName(QString newLastName)
{
    lastName = newLastName;
}
void Employee::setPatronymic(QString newPatronymic)
{
    patronymic = newPatronymic;
}
