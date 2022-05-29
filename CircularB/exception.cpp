//
// Created by Виктория on 19.05.2022.
//

#include "exception.h"

Exception::Exception(std::string error): _error(std::move(error)) {}

const char * Exception::what() const noexcept {
   return _error.c_str();
}
