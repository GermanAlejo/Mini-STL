//
// Created by german on 14/10/25.
//
#include <iostream>
#include "../../include/Vector/Vector2.h"

namespace mystl {

    //Constructor
    Vector2::Vector2(float x, float y): x(x), y(y) {};

    float Vector2::getX() {
        return x;
    }
    float Vector2::getY() {
        return x;
    }
    void Vector2::setX(float newX) {
        x = newX;
    }
    void Vector2::setY(float newY) {
        y = newY;
    }

    void Vector2::PrintVector() {
        std::cout << "\nX:" << x << ", Y:" << y << "\n";
    }

    Vector2 Vector2::operator+(const Vector2& vector) const {
        return Vector2(x + vector.x, y + vector.y);
    }

    Vector2 Vector2::operator-(const Vector2 &vector) const {
        return Vector2(x - vector.x, y - vector.y);
    }


}
