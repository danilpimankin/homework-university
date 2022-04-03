#include "PersonKeeper.h"

PersonKeeper::PersonKeeper()
{

}

PersonKeeper::~PersonKeeper()
{
    //нет динамически созданных объектов
}

PersonKeeper &PersonKeeper::Example()
{
    static PersonKeeper example;//для того чтобы не создавать ещё раз при вызове

    return example;
}


int PersonKeeper::Size()
{
    return stack.Size();
}

void PersonKeeper::Clear()
{
    return stack.Clear();
}
void PersonKeeper::readPerson(QString path)
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
        Person pip(line);

        stack.Push(pip);


    }

    file.close();
}

void PersonKeeper::writePeron(QString way) const
{
    QFile file(way);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))//проверка
    {
        throw "File not open";
    }

    QTextStream stream(&file);

    stack.Iter([&]( const Person &value)
    {
        stream << value.getLastName() << '\t' << value.getFirstName() << '\t' << value.getPatronymic() << Qt::endl;

    });

    file.close();
}
