#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H

#include<EStack.h>
#include<Person.h>
#include <QString>
#include <QTextStream>
#include <QFile>
class PersonKeeper
{
private:
    PersonKeeper();
    PersonKeeper(const PersonKeeper &);
    ~PersonKeeper();

    PersonKeeper &operator=(const PersonKeeper &);
    EStack<Person> stack;

public:

    static PersonKeeper &Example();

    void readPerson(QString way);
    void writeperson(QString way) const;

    QStringList ToQStringList() const;

    int Size();
    void Clear();
};

#endif // EMPLOYEEDATA_H
