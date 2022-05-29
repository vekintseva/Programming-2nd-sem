// Created by Виктория on 10.02.2022.

#include "fun.h"

void Round(double& x) {
    x = (int)x;
}
void Round(double* x) {
    *x = (int)(*x);
}


void Swap_sign(int& a, double& b) {
    a=a*(-1);
    b = b*(-1);
}
void Swap_sign(int* a, double* b) {
    *b = -(*b);
    *a = -(*a);
}

void CircleMove(circle& obj, double& x, double& y) {
    obj.x += x;
    obj.y += y;
}
void CircleMove(circle* obj, double* x, double* y) {
    obj->x += *x;
    obj->y += *y;
}

void ComplexMultiReal(complex& z, double& x) {
    z.re *= x;
    z.im *= x;
}
void ComplexMultiReal(complex* z, double* x) {
    z->re *= *x;
    z->im *= *x;
}


