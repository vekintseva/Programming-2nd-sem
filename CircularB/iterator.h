//
// Created by Виктория on 28.05.2022.
//

#pragma once
#include <iostream>
#include <iterator>
using namespace std;
template<class T> class ra_iterator;

template<class T>
class ra_iterator : public std::iterator<std::random_access_iterator_tag, T> {
public:
    T* index_position;
    T* array;
    T* start;
    T* end;
    unsigned int size;
    ra_iterator(T* pos, T* arr, unsigned int arr_size, T* begin, T* finish) {
        index_position = pos;
        array = arr;
        start = begin;
        end = finish;
        size = arr_size;
    }
    explicit ra_iterator(T* pos) {
        index_position = pos;
    }
    ~ra_iterator() = default;
    T& operator*() {
        return *index_position;
    };
    T* operator->() {
        return index_position;
    }
    ra_iterator& operator++() {
        ++index_position;
        return *this;
    }
    ra_iterator operator++(int) {
        ra_iterator tmp(*this);
        operator++();
        return tmp;
    }
    ra_iterator& operator--() {
        index_position--;
        return *this;
    }
    ra_iterator operator--(int) {
        ra_iterator tmp(*this);
        operator--();
        return *this;
    }
    ra_iterator operator-(typename std::iterator<std::random_access_iterator_tag, T>::difference_type it) {
        return ra_iterator(index_position - it);
    }
    bool operator==(const ra_iterator& next) const {
        return index_position == next.index_position;
    }
    bool operator!=(const ra_iterator& next) const {
        return index_position != next.index_position;
    }
    typename iterator<random_access_iterator_tag, T>::difference_type operator-(const ra_iterator<T>& it) {
        return index_position - it.index_position;
    }
    typename iterator<random_access_iterator_tag, T>::difference_type operator+(ra_iterator& it) {
        return index_position + it.index_position;
    }
    ra_iterator operator+(typename iterator<random_access_iterator_tag, T>::difference_type it) {
        return ra_iterator(index_position + it);
    }
    bool operator<(const ra_iterator& next) {
        return index_position < next.index_position;
    }
    bool operator<(T* p) {
        return index_position < p;
    }
    bool operator>(T* p) {
        return index_position > p;
    }
    bool operator<=(T* p) {
        return index_position <= p;
    }
    bool operator>=(T* p) {
        return index_position >= p;
    }
    bool operator<=(const ra_iterator& next) {
        return index_position <= next.index_position;
    }
    bool operator>(const ra_iterator& next) {
        return index_position > next.index_position;
    }
    bool operator>=(const ra_iterator& next) {
        return index_position >= next.index_position;
    }
    ra_iterator& operator+=(typename std::iterator<std::random_access_iterator_tag, T>::difference_type it) {
        index_position += it;
        return *this;
    }
    ra_iterator& operator-=(typename std::iterator<std::random_access_iterator_tag, T>::difference_type it) {
        index_position -= it;
        return *this;
    }
    ra_iterator& operator= (const ra_iterator& it) {
        index_position = it.index_position;
        return *this;
    }
    ra_iterator& operator=(T* it) {
        index_position = it;
        return *this;
    }
};

