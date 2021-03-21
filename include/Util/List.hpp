#pragma once
#include "Node.hpp"

namespace Header::Util
{
    template <class T>
    class List
    {
    public:
        List(T element);
        List();
        ~List();

#pragma region GET / SET
        Node<T> *getFirst()
        {
            return this->_first;
        }
        void setFirst(Node<T> *first) { this->_first = first; }

        Node<T> *getLast() { return this->_last; }
        void setLast(Node<T> *last) { this->_last = last; }

        unsigned int getSize() const { return this->_size; }
        void setSize(const unsigned int size) { this->_size = size; }
#pragma endregion

#pragma region Actions
        void insert(T element, unsigned int index);
        void insert(T element) { append(element); }
        void push(T element);
        void append(T element);

        void remove(T element) {}
        void pop(unsigned int index) {}
        void pop() { pop(this->getSize() - 1); }

        Node<T> *findAtIndex(unsigned int index);
        Node<T> *find(T element);

        void sort() {}
#pragma endregion

#pragma region Auxiliary Methods
    private:
        void initializeList();
        void insertFirstElement(T element);
#pragma endregion

    private:
        unsigned int _size;
        Node<T> *_first;
        Node<T> *_last;
    };
}
