//
// Created by german on 14/10/25.
//

#ifndef MINI_STL_DYNAMICARRAY_H
#define MINI_STL_DYNAMICARRAY_H

namespace mystl {
    template<typename T>
    class DynamicArray {
    private:
        T *data;
        size_t size;
        size_t capacity;

        void GrowDynamicArray() {
            T *oldData = this->data;
            size_t oldSize = this->size;
            this->capacity *= 2;
            this->data = new T[this->capacity];
            internalArrayCopy(this->data, oldData, oldSize);
            delete[] oldData;
        }

        static void internalArrayCopy(T *newArr, const T *source, const size_t arraySize) {
            for (int i = 0; i < arraySize; ++i) {
                newArr[i] = source[i];
            }
        }

    public:
        //constructors
        DynamicArray() {
            this->capacity = 2;
            this->size = 0;
            this->data = new T[this->capacity];
        }

        template<size_t N>
        explicit DynamicArray(const T (&inputData)[N]) {
            this->capacity = N;
            this->size = N;
            this->data = new T[N];
            this->internalArrayCopy(this->data, inputData, N);
        }

        explicit DynamicArray(size_t capacity) {
            this->capacity = capacity;
            this->size = 0;
            this->data = new T[capacity];
        }

        //deconstructor
        ~DynamicArray() {
            delete[] data;
        }

        int getSize() const {
            return this->size;
        }

        int getCapacity() const {
            return this->capacity;
        }

        T get(size_t index) const {
            return this->data[index];
        }

        void push(const T &data) {
            // If there is no space left, increment that space
            if (this->size >= this->capacity) {
                this->GrowDynamicArray();
            }
            this->data[this->size] = data;
            ++this->size;
        }

        T pop() {
            size_t currentSize = this->size;
            if (currentSize > 0) {
                --this->size;
                return this->data[currentSize - 1];
            }
            //Log error
            std::cout << "ERROR - Array is size 0, no elements present";
            return 0;
        }

        //we return a reference
        DynamicArray& resize(size_t newSize) {
            if (newSize > this->size) {
                T* newData = new T[newSize];
                internalArrayCopy(newData, this->data, this->size);
                delete[] this->data;
                this->data = newData;
            } else if (newSize < this->size) {
                for (size_t i = newSize; i < this->size; ++i) {
                    data[i].~T();
                }
            }

            this->size = newSize;
            this->capacity = newSize;

            return *this;
        }

        DynamicArray& operator=(const DynamicArray& originalArr) {
            if (this == &originalArr) return *this; // self-assignment check

            // Free existing memory
            delete[] data;

            // Copy new data
            capacity = originalArr.capacity;
            size = originalArr.size;
            data = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                data[i] = originalArr.data[i];
            }

            return *this;
        }

        void reserve(size_t newCapacity) {
            if (newCapacity > this->capacity) {
            }
        }

        void clear() {
            delete[] this->data;
            this->data = nullptr;
            this->size = 0;
            this->capacity = 2;
        }

        void PrintArray() const {
            std::cout << "[";
            for (int i = 0; i < this->size; ++i) {
                std::cout << this->data[i];
                if (i != this->size - 1) {
                    std::cout << " - ";
                }
            }
            std::cout << "] - SIZE: " << this->size << "\n";
        }
    };
}
#endif // MINI_STL_DYNAMICARRAY_H
