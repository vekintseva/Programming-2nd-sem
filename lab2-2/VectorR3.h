//
// Created by Виктория on 11.02.2022.
//
#pragma once //защита от повторного подключения

// Функциональность:
// Сложение и вычитание векторов
// Длина вектора
// Угол с другим вектором
// Вывод на экран (в любом виде)

#include <ostream>

class VectorR3 {
private:
    double x;
    double y;
    double z;
public:

    VectorR3(); // Конструктор по умолчанию

    VectorR3(const VectorR3 &);// Конструктор копирования

    VectorR3(double, double, double);// Конструктор трёх вещественных чисел

    VectorR3(double, double, double, double, double, double);// Конструктор вектора (2вектора с тремя координатами)

    ~VectorR3() = default;//Дестру́ктор — специальный метод класса, служащий для деинициализации объекта(например освобождения памяти).

    friend std::ostream& operator<< (std::ostream &out, const VectorR3 &); //friend предоставляет доступ к приватным полям и методам
   // static VectorR3 VectorPlus(VectorR3&, VectorR3&); // Сложение векторов
  //  static VectorR3 VectorMinus(VectorR3&, VectorR3&); // Вычитание векторов
    static double VectorLength(VectorR3&); // Длина вектора
    static double VectorsAngle(VectorR3&, VectorR3&); // Угол между векторами

    VectorR3 operator+(const VectorR3& v ) const;
    VectorR3 operator-(const VectorR3& v) const;
};