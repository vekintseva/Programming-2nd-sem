//
// Created by Виктория on 24.02.2022.
//

#pragma once

/* Треугольник на плоскости
Реализовать:
Равенство площадей треугольников (перегрузить операции
==, !=, <, >) – для вычисления площади можно
использовать, например, формулу Герона (зависит от тех
данных, что используются для хранения треугольника).
Прибавление вектора (смещение треугольника на указанный вектор). */

#include <ostream>

class Triangle {
private:
    double aX, aY;
    double bX, bY;
    double cX, cY;
public:
    Triangle(double, double, double, double, double, double);

    friend bool operator==(const Triangle& triangle1, const Triangle& triangle2);
    friend bool operator!=(const Triangle& triangle1, const Triangle& triangle2);
    friend bool operator>(const Triangle& triangle1, const Triangle& triangle2);
    friend bool operator<(const Triangle& triangle1, const Triangle& triangle2);
    friend std::ostream& operator<< (std::ostream &out, const   Triangle &);
    double TriangleSquare() const;
    static void MoveOnVector(Triangle&, double, double);

};