//
// Created by Виктория on 07.04.2022.
//
/*
#pragma once

#include <iostream>
#include "Exception.h"

//template <class T,int N>
template <class T>
class Array {

private:
    int length;
    T* data;

public:
    Array() {
        length = 0;
        data = nullptr;
    }

    explicit Array(int length_) {  //конструктор предотвращает неявное преобразование типов при инициализации
        length = length_;
        data = new T[length];
    }

    void FillArray() {
        for (int i = 0; i < length; i++) {
            std::cin >> data[i];
        }
    }

    void DeleteArray() {
        delete[] data;
        data = nullptr;
        length = 0;
    }

    int GetLength() {
        return length;
    }

    T& operator[](int index) {
        if (index < 0 || index >= length)  //исключительное условие
            throw Exception("Index out of range!");
        return data[index];
    }

    void ShowArray() {
        for (int i = 0; i < length; i++)
            std::cout << data[i] << " ";
    }

    ~Array() = default;
}; */

#pragma once

#include <iostream>
#include "Exception.h"

template <class T,int N>
class Array {

    int length=N;
    T* data;

public:

    Array<T,N>()
    {
        data = nullptr;
    }

   explicit Array(int) {  //конструктор предотвращает неявное преобразование типов при инициализации
        length = N;
        data = new T[length];
    }

    void FillArray() {
        for (int i = 0; i < length; i++) {
            std::cin >> data[i];
        }
    }

    void DeleteArray() {
        delete[] data;
        data = nullptr;
        length = 0;
    }

    int GetLength() {
        return length;
    }

    T& operator[](int index) {
        if (index < 0 || index >= length)  //исключительное условие
            throw Exception("Index out of range!");
        return data[index];
    }

    void ShowArray() {
        for (int i = 0; i < length; i++)
            std::cout << data[i] << " ";
    }

    ~Array() = default;
};