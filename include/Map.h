//
// Created by german on 5/11/25.
//

#pragma once

#ifndef MINI_STL_MAP_H
#define MINI_STL_MAP_H

#include "common.h"

namespace mystl {
    template<typename K, typename V>
        requires std::equality_comparable<K>
    class Map {
    private:
        struct Pair {
            K key;
            V value;
            //constructor
            Pair(): key(), value() {}

            Pair(const K &key, const V &value) : key(key), value(value) {
            }

            Pair& operator=(const Pair& original) {
                if (this == &original) return *this; // self-assignment check

                // Copy new data
                key = original.key;
                value = original.value;

                return *this;
            }

            void Print() {
                std::cout << "[" << key << "," << value << "]";
            }
        };

        Pair *data;
        size_t size;
        size_t capacity;

        void growInternalArray() {
            Pair *oldData = this->data;
            size_t oldSize = this->size;
            this->capacity *= 2;
            this->data = new Pair[capacity];
            internalArrayCopy(this->data, oldData, oldSize);
            delete[] oldData;
        }

        static void internalArrayCopy(Pair *newArr, const Pair *source, const size_t arraySize) {
            for (int i = 0; i < arraySize; ++i) {
                newArr[i] = source[i];
            }
        }

    public:
        Map() {
            size = 0;
            capacity = 2;
            data = new Pair[capacity];
        }

        //Delete here all pairs and set capacity to 0
        ~Map() {
        }

        bool contains(K key) {
            for (size_t i = 0; i < size; i++) {
                if (Pair current = data[i]; key == current.key) {
                    return true;
                }
            }
            return false;
        }

        void insert(K key, V value) {
            if (!contains(key)) {
                if (size == capacity) {
                    //grow map and increment size
                    this->growInternalArray();
                }
                data[size] = Pair(key, value);
            } else {
                //update value
                K current;
                size_t i = 0;
                while (current != key) {
                    current = data[i].key;
                }
                data[i].value = value;
            }
            size++;
        }

        Map &operator=(const Map &originalMap) {
            if (this == &originalMap) return *this; // self-assignment check

            // Free existing memory
            delete[] data;

            // Copy new data
            capacity = originalMap.capacity;
            size = originalMap.size;
            data = new Pair[capacity];
            for (size_t i = 0; i < size; ++i) {
                data[i] = originalMap.data[i];
            }

            return *this;
        }

        void print() const {
            size_t i = 0;
            while (i < size) {
                data->Print();
                ++i;
            }
            std::cout << "\n";
        }
    };
}

#endif //MINI_STL_MAP_H
