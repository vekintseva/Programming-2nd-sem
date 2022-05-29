//
// Created by Виктория on 07.04.2022.
//


#include "Exception.h"

Exception::Exception(const char *const message_)
        : message(message_)
{}

const char *Exception::what() const noexcept {
    return message;
}

