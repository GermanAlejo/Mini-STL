
#pragma once
#ifndef MINI_STL_QUEUE_H
#define MINI_STL_QUEUE_H

#include "common.h"

namespace mystl {
    template<typename T>
    class Queue {
        private:
            LinkedList<T> internalList;
            
        public:
            //constructors
            Queue(): internalList() {
                
            }

            template<size_t N>
            Queue(const T (&inputData)[N]): internalList(inputData) {
                
            }

            void enqueue(T val) {
                internalList.pushBack(val);
            }

            T dequeue() {
                return internalList.popFront();
            }

            T front() {
                return internalList.getElement(0);
            }

            T back() {
                return internalList.getElement(internalList.getSize() - 1);
            }

            bool isEmpty() {
                return internalList.isEmpty();
            }

            int getSize() {
                return internalList.getSize();
            }

            void clear() {
                internalList.clear();
            }

            void printQueue() {
                internalList.printList();
            }

    };
}

#endif