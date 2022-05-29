//
// Created by Виктория on 07.04.2022.
//

#pragma once

#include <exception>

class Exception :public std::exception {
private:
    const char* message;
public:
    Exception(const char* const );
    [[nodiscard]] const char* what() const noexcept override; //nodiscard указывает, что возвращаемое функцией значение нельзя игнорировать
                                                             // и нужно сохранить в какую-либо переменную
};