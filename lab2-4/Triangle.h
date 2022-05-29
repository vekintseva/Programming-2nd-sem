//
// Created by Виктория on 24.03.2022.
//

#pragma once
#include "Base.h"

class Triangle : public IFigure {
public:
    Triangle();
    ~Triangle();
    //override используется в классе-потомке, чтобы указать что функция должна переопределять виртуальную функцию, объявленную в базовом классе.
    double square() override;
    double perimeter() override;
    double mass() const override;
    CVector2D position() const override; //позиция задается при помощи координат
    bool operator==(const IPhysObject& obj) const override;
    bool operator<(const IPhysObject& obj) const override;
    void draw() override;
    void initFromDialogue() override;
    const char* className() override;
    unsigned int size() override;
private:
    //треугольник состоит из трех координат
    CVector2D A;
    CVector2D B;
    CVector2D C;
    double weight = 0;
    const char* name = "Triangle";
};