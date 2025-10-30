#pragma once
#ifndef MINI_STL_STACK_H
#define MINI_STL_STACK_H

#include "common.h"

namespace mystl {
    template<typename T>
    class Stack {
        private:
            DynamicArray<T> internalArray;

        public:
            //constructors
            Stack(): internalArray() {
                
            }

            template<size_t N>
            Stack(const T (&inputData)[N]): internalArray(inputData) {
                
            }

            T top() {
                if (internalArray.getSize() > 0) {
                    return internalArray.get(0);
                }
                throw std::out_of_range("Empty Array");
            }

            //always push at top
            void push(T value) {
                DynamicArray<T> newArray({value});
                for (int i = 0; i < internalArray.getSize(); ++i) {
                    newArray.push(internalArray.get(i));
                }
                //maybe call clear here???
                internalArray = newArray;
            }

            //always remove top
            T pop() {
                int length = internalArray.getSize();
                T val;
                if(length > 0) {
                    DynamicArray<T> newArray;
                    for (int i = 0; i < length; ++i) {
                        if (i == 0) {
                            val = internalArray.get(i);
                        } else {
                            newArray.push(internalArray.get(i));
                        }
                    }
                    internalArray = newArray;
                    return val;
                }
                throw std::out_of_range("Index out of bounds");
            }

            int getLength() {
                return internalArray.getSize();
            }

            bool isEmpty() {
                return internalArray.getSize() == 0 ? true : false;
            }

            void clear() {
                internalArray.clear();
            }

            void printStack() {
                this->internalArray.PrintArray();
            }
            

    };
}

#endif