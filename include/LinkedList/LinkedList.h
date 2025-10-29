//
// Created by german on 29/10/25.
//

#pragma once
#ifndef MINI_STL_LINKEDLIST_H
#define MINI_STL_LINKEDLIST_H

#include "../common.h"

namespace mystl {
    template<typename T>
    class LinkedList {
    private:
        struct Node {
            T data;
            Node *prev;
            Node *next;
            //constructor
            explicit Node(const T value) : data(value), prev(nullptr), next(nullptr) {
            }
        };

        Node *head;
        Node *tail;
        size_t listSize;

        Node *traverseNode(const size_t pos) {
            Node *current = head;
            for (size_t i = 0; i < pos; ++i) {
                current = current->next;
            }
            return current;
        }

    public:
        LinkedList() {
            head = nullptr;
            tail = nullptr;
            listSize = 0;
        }

        LinkedList(std::initializer_list<T> inputData) : head(nullptr), tail(nullptr), listSize(0) {
            for (const T &data: inputData) {
                Node *newNode = new Node(data);
                if (!head) {
                    head = newNode;
                    tail = head;
                } else {
                    tail->next = newNode;
                    newNode->prev = tail;
                    tail = newNode;
                }
                ++this->listSize;
            }
        }

        ~LinkedList() {
            Node* current = head;
            while (current) {
                Node* nextNode = current->next; // store next node
                delete current;                 // delete current node
                current = nextNode;             // move to next
            }
            head = nullptr;
            tail = nullptr;
            listSize = 0;
        }

        T &getElement(const size_t index) {
            return traverseNode(index)->data;
        }

        void pushFront(T value) {
            Node *newNode = new Node(value);
            if (!head) {
                head = newNode;
                tail = head;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            ++listSize;
        }

        void pushBack(T value) {
            Node *newNode = new Node(value);
            if (!head) {
                head = newNode;
                tail = head;
            } else {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
        }

        T popFront() {
            if (!head) {
                //error
                throw std::out_of_range("List is empty");
            }

            Node *oldFront = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            T val = oldFront->data;
            delete oldFront;
            --this->listSize;
            return val;
        }

        void printList() {
            Node *current = this->head;
            std::cout << "First: " << current->data;
            for (size_t i = 0; i < this->listSize; ++i) {
                if (current == tail) {
                    std::cout << " - END\n";
                } else {
                    current = current->next;
                    std::cout << "->" << current->data;
                }
            }
        }
    };
}

#endif //MINI_STL_LINKEDLIST_H
