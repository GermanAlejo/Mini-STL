#include <iostream>
#include <string>
#include "../include/Vector/Vector2.h"
#include "../include/DynamicArray.h"
#include "../include/LinkedList/LinkedList.h"

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
    /*
    mystl::DynamicArray<int> newDrray(10);
    newDrray.PrintArray();

    newDrray.push(2);
    newDrray.push(1);
    newDrray.push(3);
    newDrray.PrintArray();

    int aux = newDrray.pop();
    std::cout << "Element: " << aux << "\n";
    newDrray.PrintArray();

    float numbers[] = {2.1, 1.2};
    mystl::DynamicArray<float> array2(numbers);
    std::cout << "New Array: \n";
    array2.PrintArray();
    array2.push(1.0);
    array2.PrintArray();

    std::cout << "String Array: \n";
    mystl::DynamicArray<std::string> arrayStr;
    arrayStr.push("test");
    std::string s = "test2";
    arrayStr.push(s);
    arrayStr.PrintArray();
    std::string s2 = arrayStr.pop();
    arrayStr.PrintArray();
    std::cout << "Poped: " << s2 << "\n";
    std::cout << "Get second from int array: " << newDrray.get(1) << "\n";
    std::cout << "Incrementing size by 2\n";
    newDrray.resize(4);
    newDrray.PrintArray();
    std::cout << "Decrementing size by 2\n";
    newDrray.resize(2);
    newDrray.PrintArray();
    std::cout << "Testing method chaining, current size: " << newDrray.getSize() <<"\n";
    newDrray.resize(3).push(1);
    newDrray.PrintArray();

    std::cout << "testing copy operator overload, coping: ";
    newDrray.PrintArray();
    mystl::DynamicArray<int> array4 = newDrray;
    std::cout << "copy: ";
    array4.PrintArray();

    newDrray.push(2);
    newDrray.PrintArray();

    array4.push(1);
    array4.PrintArray();
*/
    std::cout << "Testing Linked lists\n";
    mystl::LinkedList<int> newList({1,2,3});
    newList.printList();
    std::cout << "Get second: " << newList.getElement(1) << "\n";
    newList.pushFront(4);
    newList.printList();
    newList.pushBack(5);
    newList.printList();
    std::cout << "\nPopped: " << newList.popFront() << "\n";
    newList.printList();
    std::cout << "\nInsert value: 6 in pos 2\n";
    newList.insertValue(2, 6);
    newList.printList();
    std::cout << "\nPop back:" << newList.popBack() << "\n";
    newList.printList();

    return 0;
}
