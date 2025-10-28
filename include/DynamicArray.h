//
// Created by german on 14/10/25.
//

#ifndef MINI_STL_DYNAMICARRAY_H
#define MINI_STL_DYNAMICARRAY_H

namespace mystl
{
    template <typename T>
    class DynamicArray
    {
    private:
        T *data;
        size_t size;
        size_t capacity;

        void GrowDynamicArray()
        {
            T *oldData = this->data;
            size_t oldSize = this->size;
            this->capacity *= 2;
            this->data = new T[oldSize];
            for (int i = 0; i < oldSize; i++)
            {
                this->data[i] = oldData[i];
            }
            delete[] oldData;
        }

    public:
        DynamicArray(size_t capacity)
        {
            this->capacity = capacity;
            this->size = 0;
            this->data = new T[capacity];
        };

        int getSize() {
            return this->size;
        }

        void push(T data)
        {
            // If there is no space left, increment that space
            if (this->size >= this->capacity)
            {
                this->GrowDynamicArray();
            }
            this->data[this->size] = data;
            this->size++;
        }

        T pop() 
        {
            size_t currentSize = this->size;
            if(currentSize > 0) {
                this->size--;
                return this->data[currentSize - 1];
            }
            //Log error
            std::cout << "ERROR - Array is size 0, no elements present";
            return 0;
        }

        void PrintArray()
        {
            std::cout << "[";
            for (int i = 0; i < this->size; i++)
            {
                std::cout << this->data[i];
                if (i != this->size - 1)
                {
                    std::cout << " - ";
                }
            }
            std::cout << "]\n";
        }
    };

}
#endif // MINI_STL_DYNAMICARRAY_H