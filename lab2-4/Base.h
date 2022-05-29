//
// Created by Виктория on 24.03.2022.
//
#pragma once
#include <fstream>

class IGeoFig { //интерфейс Геометрическая фигура
public:
    virtual double square() = 0; //площадь
    virtual double perimeter() = 0; //периметр
};

class CVector2D { //вектор
public:
    double x,y;
    CVector2D();
    friend std::istream& operator>>(std::istream&, CVector2D&); //friend-функция, которая не является членом класса,
                                                               // но имеет доступ к закрытым и защищенным членам класса.
    friend std::ostream& operator<<(std::ostream&, const CVector2D&);
};

class IPhysObject { //Интерфейс физический объект
public:
    virtual double mass() const = 0; //масса
    virtual CVector2D position() const = 0; //координаты центра
    virtual bool operator==(const IPhysObject& obj) const = 0; //сравнение по массе
    virtual bool operator<(const IPhysObject& obj) const = 0; //сравнение по массе

};

class IPrintable  //Интерфейс Отображаемый
{
public:
    virtual void draw() = 0; // Отобразить на экране; (выводить в текстовом виде параметры фигуры).
};

class IDialogueInitiable //Интерфейс для классов, которые можно задать через диалог с пользователем
{
public:
    virtual void initFromDialogue() = 0; //задать парметры объекты с помощью диалога с пользователем
};

class BaseCObject //Интерфейс класс
{
public:
    virtual const char* className() = 0; //имя класса
    virtual unsigned int size() = 0; //размер занимаемой памяти
};

class IFigure : public IGeoFig, public IPhysObject, public IPrintable, public IDialogueInitiable, public BaseCObject
{

};