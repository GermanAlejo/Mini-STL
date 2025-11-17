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
            Pair() noexcept: key(), value() {
            }

            Pair(const K &key, const V &value) noexcept : key(key), value(value) {
            }

            Pair &operator=(const Pair &original) noexcept {
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

        size_t capacity;
        size_t size;
        Pair *data;

        void growInternalArray() {
            Pair *oldData = this->data;
            size_t oldSize = this->size;
            this->capacity *= 2;
            this->data = new Pair[capacity];
            internalArrayCopy(this->data, oldData, oldSize);
            delete[] oldData;
        }

        static void internalArrayCopy(Pair *newArr, const Pair *source, const size_t arraySize) {
            for (size_t i = 0; i < arraySize; ++i) {
                newArr[i] = source[i];
            }
        }

    public:
        Map(): capacity(2), size(0), data(nullptr) {
            data = new Pair[capacity];
        }

        //deep copy
        Map(const Map& other): capacity(other.capacity), size(other.size), data(new Pair[other.capacity])
        {
            for (size_t i = 0; i < size ; ++i) {
                data[i] = other.data[i];
            }
        }

        //move constructor
        Map(Map&& other) noexcept: capacity(other.capacity), size(other.size), data(other.data) {
            other.size = 0;
            other.capacity = 0;
            other.data = nullptr;
        }

        Map& operator=(Map&& other) noexcept {
            swap(*this, other);
            return *this;
        }

        Map& operator=(const Map &originalMap) noexcept {
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

        //Delete here all pairs and set capacity to 0
        ~Map() {
            delete[] data;
        }

        friend void swap(Map& a, Map& b) noexcept {
            using std::swap;
            swap(a.size, b.size);
            swap(a.capacity, b.capacity);
            swap(a.data, b.data);
        }

        V* find(const K& key) const {
            for (size_t i = 0; i < size; ++i) {
                if (key == data[i].key) {
                    return &data[i].value;
                }
            }
            return nullptr;
        }

        bool contains(const K& key) const {
            for (size_t i = 0; i < size; ++i) {
                if (key == data[i].key) {
                    return true;
                }
            }
            return false;
        }

        void insert(const K& key, const V& value) {
            if (!contains(key)) {
                if (size == capacity) {
                    //grow map and increment size
                    this->growInternalArray();
                }
                data[size] = Pair(key, value);
                size++;
            } else {
                //update value
                size_t i = 0;
                K current = data[i].key;
                while (current != key) {
                    current = data[++i].key;
                }
                data[i].value = value;
            }
        }

        void erase(K key) {
            size_t index = size; // sentinel equal to "not found"
            for (size_t i = 0; i < size; ++i) {
                if (key == data[i].key) {
                    //encontrado
                    index = i;
                    break;
                }
            }

            if (index == size) {
                //no encontrado
                return;
            }

            for (size_t j = index; j < size - 1; ++j) {
                data[j] = data[j + 1];
            }

            --size;
        }

        void clear() {
            size = 0;
        }

        size_t getSize() const {
            return size;
        }

        void print() const {
            size_t i = 0;
            while (i < size) {
                data[i].Print();
                ++i;
            }
            std::cout << "\n";
        }
    };
}

#endif //MINI_STL_MAP_H
