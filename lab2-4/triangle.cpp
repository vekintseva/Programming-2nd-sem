//
// Created by Виктория on 24.03.2022.
//

#include "Triangle.h"
#include <iostream>
#include<math.h>

Triangle::~Triangle() = default;
Triangle::Triangle()
{
    this->Triangle::initFromDialogue();
}
double Triangle::square() //площадь
{
    return ((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y)) / 2;
}
double Triangle::perimeter() //периметр
{
    return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2)) + sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2)) + sqrt(pow(C.x - A.x, 2) + pow(C.y - A.y, 2));
}
double Triangle::mass() const //масса
{
    return weight;
}
CVector2D Triangle::position() const
{
    CVector2D center;
    center.x = (A.x + B.x + C.x) / 3;
    center.y = (A.y + B.y + C.y) / 3;
    return center;
}

//внизу представлены 2 функции, необходимые для сравнения масс
bool Triangle::operator==(const IPhysObject & object) const
{
    return mass() == object.mass();
}
bool Triangle::operator<(const IPhysObject & object) const
{
    return mass() < object.mass();
}
void Triangle::draw() //вывод описания фигуры
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Position: " << position() << std::endl;
    std::cout << "Weight: " << weight << std::endl;
    std::cout << "Size: " << size() << std::endl;
    std::cout << std::endl;
}
void Triangle::initFromDialogue() //диалог с пользоватеем для ввода всех необходимыхм параметров
{
    std::cout << "\t\tAdd first coords: ";
    std::cin >> A;
    std::cout << "\t\tAdd first coords: ";
    std::cin >> B;
    std::cout << "\t\tAdd first coords: ";
    std::cin >> C;
    std::cout << "\t\tAdd weight: ";
    std::cin >> weight;
}
const char* Triangle::className() //имя фигуры
{
    return name;
}
unsigned Triangle::size() //размер
{
    return sizeof(*this);
}