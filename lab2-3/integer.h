//
// Created by Виктория on 24.02.2022.
//
#pragma once
#include <ostream>

// Подмножество множества целых чисел от нуля до
// девяти: { 0, 1, 2, ... 9 }.

// Операторы:
// Объединение двух множеств (operator+).
// Сравнение (== и !=).
// Добавление числа в множество (operator+=).
// Изъятие числа из множества (operator-=).

class CSet {
private:
    bool Set[10] = {}; //множество на 10 элементов
public:
    CSet();
    explicit CSet(int); //объявление конструктора с одним параметром

    friend bool operator==(const CSet& set1, const CSet& set2);
    friend bool operator!=(const CSet& set1, const CSet& set2);
    bool& operator[](int index);
    bool operator[](int index) const;
    friend CSet operator+(CSet set1, CSet set2);
    friend void operator+=(CSet&, int);
    friend void operator-=(CSet&, int);
    friend std::ostream& operator<<(std::ostream &out, const CSet &); //вывод множества

};