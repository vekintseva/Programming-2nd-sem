//
// Created by Виктория on 19.05.2022.
//

#ifndef CIRCULARB_EXCEPTION_H
#define CIRCULARB_EXCEPTION_H
#include <iostream>

class Exception: public std::exception {
    std::string _error;

public:
    Exception(std::string);

    const char * what() const noexcept override;
};


#endif //CIRCULARB_EXCEPTION_H