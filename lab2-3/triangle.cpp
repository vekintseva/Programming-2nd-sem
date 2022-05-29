//
// Created by Виктория on 24.02.2022.
//

#include "triangle.h"
#include <cmath>
using namespace std;

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3) : aX(x1), aY(y1), bX(x2), bY(y2), cX(x3), cY(y3) {
}

double Triangle::TriangleSquare() const {
    return std::abs((bX - aX) * (cY - aY) - (cX-aX) * (bY - aY)) / 2;
}

bool operator==(const Triangle &triangle1, const Triangle &triangle2) {
    return triangle1.TriangleSquare() == triangle2.TriangleSquare();
}

bool operator!=(const Triangle &triangle1, const Triangle &triangle2) {
    return triangle1.TriangleSquare() != triangle2.TriangleSquare();
}

bool operator>(const Triangle &triangle1, const Triangle &triangle2) {
    return triangle1.TriangleSquare() > triangle2.TriangleSquare();
}

bool operator<(const Triangle &triangle1, const Triangle &triangle2) {
    return triangle1.TriangleSquare() < triangle2.TriangleSquare();
}

void Triangle::MoveOnVector(Triangle & triangle, double x, double y) {
    triangle.aX += x;
    triangle.aY += y;
    triangle.bX += x;
    triangle.bY += y;
    triangle.cX += x;
    triangle.cY += y;
}

    ostream &operator<<(std::ostream &out, const Triangle & triangle) { //использую ostream out для вывода на консоль
    out << "Point1: " << "(" << triangle.aX << ", " << triangle.aY << ")" << endl;
    out << "Point2: " << "(" << triangle.bX << ", " << triangle.bY << ")" << endl;
    out << "Point3: " << "(" << triangle.cX << ", " << triangle.cY << ")" << endl;
    return out;
}


