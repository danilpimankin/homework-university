#include "EmployeeData.h"

EmpData::EmpData()
{

}

EmpData::~EmpData()
{
    //нет динамически созданных объектов
}

EmpData &EmpData::Example()
{
    static EmpData example;//для того чтобы не создавать ещё раз при вызове

    return example;
}


int EmpData::Size()
{
    return stack.Size();
}

void EmpData::Clear()
{
    return stack.Clear();
}
void EmpData::readEmp(QString path)
{
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))//проверка
    {
        throw "File not open";
    }

    QTextStream stream(&file);//данные из файла
    QString line;//строка для считывания

    while (stream.readLineInto(&line))
    {
        Employee pip(line);

        stack.Push(pip);


    }

    file.close();
}

void EmpData::writeEmp(QString way) const
{
    QFile file(way);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))//проверка
    {
        throw "File not open";
    }

    QTextStream stream(&file);

    stack.Iter([&]( const Employee &value)
    {
        stream << value.getLastName() << '\t' << value.getFirstName() << '\t' << value.getPatronymic() << Qt::endl;

    });

    file.close();
}
