#ifndef EMPLOYEEDATA_H
#define EMPLOYEEDATA_H

#include<EStack.h>
#include<Employee.h>
#include <QString>
#include <QTextStream>
#include <QFile>
class EmpData
{
private:
    EmpData();
    EmpData(const EmpData &);
    ~EmpData();

    EmpData &operator=(const EmpData &);
    EStack<Employee> stack;

public:

    static EmpData &Example();

    void readEmp(QString way);
    void writeEmp(QString way) const;

    QStringList ToQStringList() const;

    int Size();
    void Clear();
};

#endif // EMPLOYEEDATA_H
