#include <iostream>
#include "../include/Vector/Vector2.h"
#include "../include/DynamicArray.h"

int main() {

    //mystl::Vector2 vector (1.2f, 2.2f);
    //vector.PrintVector();
    //mystl::Vector2 vector2 (1.2f, 2.2f);
    //vector2.PrintVector();
    //mystl::Vector2 vector3 = vector + vector2;
    //vector3.PrintVector();
//
    //mystl::Vector2 vector4 = vector3 - vector2;
    //vector4.PrintVector();
    mystl::DynamicArray<int> newDrray(10);
    newDrray.PrintArray();

    newDrray.push(2);
    newDrray.push(1);
    newDrray.push(3);
    newDrray.PrintArray();

    int aux = newDrray.pop();
    std::cout << "Element: " << aux << "\n";
    newDrray.PrintArray();

    return 0;
}
