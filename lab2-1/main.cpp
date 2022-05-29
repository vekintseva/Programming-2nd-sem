#include <iostream>
#include "fun.h"

using namespace std;

void first() { //4.Отбрасывает от вещественного числа его дробную часть
    cout << endl;
    cout << "    Task 1:" << endl;
    double a2 = 10.15, b2 = 54.45;
    cout << "Values: " << a2 << " " << b2 << endl;
    Round(a2);
    cout << "Discards the fractional part with links: " << a2 << endl;
    Round(&b2);
    cout << "Discards the fractional part with pointers: " << b2 << endl;
}

 void second() { //7.меняет знак переменной (вещественной, целой)
     cout << endl;
     cout << "    Task 2:" << endl;
     int a1 = 12;  double b1 = 45.3;
     cout << "Values: " << a1 << " " << b1 << endl;
     Swap_sign(a1, b1);
     cout << "Swap sign with links: " << a1 << " " << b1 <<endl;
     Swap_sign(&a1, &b1);
     cout << "Swap sign with pointers: " << a1 << " " << b1 << endl;
 }


void third() {  // 12. сдвигает окружность на заданный вектор
    cout << std::endl;
    cout << "    Task 3:" << endl;
    circle a3;
    a3.x = 1, a3.y = 5;
    double x = 5, y = -3;
    cout << "Circle center coords: " << "(" << a3.x << ";" << a3.y << ")" << endl;
    cout << "Vector: " << "{" << x << ";" << y << "}" << endl;
    CircleMove(a3, x, y);
    cout << "Move center of the circle coords with links: " << "(" << a3.x << ";" << a3.y << ")" << endl;
    CircleMove(&a3, &x, &y);
    cout << "Move center of the circle coords with pointers: " << "(" << a3.x << ";" << a3.y << ")" << endl;
}

void fourth() { //9.комплексная переменная * вещественное число
    cout << endl;
    cout << "    Task 4:" << endl;
    complex a3;
    a3.im = 2, a3.re = 3;
    double b3 = 1.25;
    cout << "Values: " << a3.re << "+" << a3.im << "i" << " " << b3 << endl;
    ComplexMultiReal(a3, b3);
    cout << "Multiplies a complex variable by real number with links: " << a3.re << "+" << a3.im << "i" << endl;
    ComplexMultiReal(&a3, &b3);
    cout << "Multiplies a complex variable by real number with pointers: " << a3.re << "+" << a3.im << "i" << endl;
}



int main() {
    first();
    second();
    third();
    fourth();
}