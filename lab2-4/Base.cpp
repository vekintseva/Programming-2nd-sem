//
// Created by Виктория on 24.03.2022.
//

#include "Base.h"
using namespace std;

CVector2D::CVector2D(): x(0), y(0)
{
    double x = 0;
    double y = 0;
}
istream& operator>>(istream& stream, CVector2D& vector) //istream/jstream - базовый класс
{
    stream >> vector.x >> vector.y;
    return stream;
}
ostream& operator<<(ostream& stream, const CVector2D& vector)
{
    stream << "(" << vector.x << ";" << vector.y << ")";
    return stream;
}