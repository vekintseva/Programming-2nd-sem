//
// Created by Виктория on 11.02.2022.
//
#include "VectorR3.h"
#include <cmath>

VectorR3::VectorR3() : x(1.0), y(1.0), z(1.0) {

}

VectorR3::VectorR3(const VectorR3 &copy) : x(copy.x), y(copy.y), z(copy.z) {

}

VectorR3::VectorR3(double i, double j, double k) : x(i), y(j), z(k) {

}

VectorR3::VectorR3(double x1, double y1, double z1, double x2, double y2, double z2) : x(x2-x1), y(y2-y1), z(z2-z1) {

}

double VectorR3::VectorLength(VectorR3 & a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

double VectorR3::VectorsAngle(VectorR3 & a, VectorR3 & b) {
    return acos((a.x * b.x + a.y * b.y + a.z * b.z) / (VectorLength(a) * VectorLength(b)));
}

VectorR3 VectorR3::operator+(const VectorR3& a) const
{
    return {a.x + this->x, a.y + this->y, a.z + this->z};
}

VectorR3 VectorR3::operator-(const VectorR3& a) const
{
    return {x-a.x, y-a.y, z-a.z};
}

std::ostream &operator<<(std::ostream &out, const VectorR3 & a) {
    out << "(" << a.x << ", " << a.y << ", " << a.z << ")";
    return out;
}
