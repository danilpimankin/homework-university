#include "Person.h"

Person::Person()//конструктор
{
    firstName = "pip";
    lastName = "piip";
    patronymic = "piiip";
}
Person::Person(QString fullName)
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
Person::Person(const Person& person)
{
    firstName = person.firstName;
    lastName = person.lastName;
    patronymic = person.patronymic;
}

void Person::setFirstName(QString newFirstName)
{
    firstName = newFirstName;
}
void Person::setLastName(QString newLastName)
{
    lastName = newLastName;
}
void Person::setPatronymic(QString newPatronymic)
{
    patronymic = newPatronymic;
}
