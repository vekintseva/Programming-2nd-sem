// Created by Виктория on 10.02.2022.

#pragma once
void Round(double&);
void Round(double*);

void Swap_sign(int&, double&);
void Swap_sign(int*, double*);

struct circle {
    double x;
    double y;
};
void CircleMove(circle&, double&, double&);
void CircleMove(circle*, double*, double*);


struct complex { // для 9
    double re;
    double im;
};
void ComplexMultiReal(complex&, double&);
void ComplexMultiReal(complex*, double*);




