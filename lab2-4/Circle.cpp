//
// Created by Виктория on 24.03.2022.
//

#include "Circle.h"
#include "Base.h"

#include <math.h>
#include <iostream>
const double pi = M_PI;

Circle::~Circle() = default;
Circle::Circle()
{
    this->Circle::initFromDialogue();
}
double Circle::square() //площадь
{
    return pi * pow(radius, 2);
}

double Circle::perimeter() //периметр
{
    return 2 * pi * radius;
}

double Circle::mass() const //масса
{
    return weight;
}

CVector2D Circle::position() const //позиция (определяеся по центральной координате)
{
    return center;
}

//далее пред ставлены две функции, необходимые для сравнения масс
bool Circle::operator==(const IPhysObject& object) const
{
    return mass() == object.mass();
}

bool Circle::operator<(const IPhysObject& object) const
{
    return mass() < object.mass();
}

void Circle::draw() //отображение всех данных  о фигуре
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Position: " << center << std::endl;
    std::cout << "Radius: " << radius << std::endl;
    std::cout << "Weight: " << weight << std::endl;
    std::cout << "Size: " << size() << std::endl;
}
void Circle::initFromDialogue() //с помощью данной функции осуществляется ввод всех данных, касаемых окружности
{
    std::cout << "\t\tAdd center coords: ";
    std::cin >> center;
    std::cout << "\t\tAdd radius: ";
    std::cin >> radius;
    std::cout << "\t\tAdd weight: ";
    std::cin >> weight;
}

const char* Circle::className() //имя фигуры
{
    return name;
}
unsigned Circle::size() //размер
{
    return sizeof(*this);
}