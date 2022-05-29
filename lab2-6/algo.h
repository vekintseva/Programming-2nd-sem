//
// Created by Виктория on 21.04.2022.
//

#pragma once

#include <iterator>
#include <functional>


template<typename InputIterator, typename T>
bool anyOf(InputIterator first, InputIterator last, T value) {
    for (; first != last; first++) //цикл
        if (value(*first))
            return true;
    return false;
}

template<typename InputIterator, typename T>
bool noneOf(InputIterator first, InputIterator last, T value) {
    for (first; first != last; first++)
        if (value(*first) == 1)
            return false;
    return true;
}

template <typename InputIterator, typename T = std::less<>>
bool isSorted(InputIterator first, InputIterator last, T value = T()) {
    InputIterator prevIt = first;
    for (auto it = next(first); it != last; it = next(it)) {
        if (!value(*prevIt, *it)) {
            return false;
        }
    }
    return true;
}


template<typename InputIterator, typename T>
bool isPalindrome(InputIterator first, InputIterator last, T value) {
    InputIterator right = first;
    --last;

    while (first != last && right != last) {
        if (value(*first, *last) == 0)
            return false;
        right = first;
        ++first;
        --last;
    }
    return true;
}

