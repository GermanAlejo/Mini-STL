#include <iostream>
#include "../include/Vector/Vector2.h"

int main() {

    mystl::Vector2 vector (1.2f, 2.2f);
    vector.PrintVector();
    mystl::Vector2 vector2 (1.2f, 2.2f);
    vector2.PrintVector();
    mystl::Vector2 vector3 = vector + vector2;
    vector3.PrintVector();

    mystl::Vector2 vector4 = vector3 - vector2;
    vector4.PrintVector();
    return 0;
}
