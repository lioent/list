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
        Node<T> *first()
        {
            return this->_first;
        }
        void first(Node<T> *first) { this->_first = first; }

        Node<T> *last() { return this->_last; }
        void last(Node<T> *last) { this->_last = last; }

        unsigned int size() const { return this->_size; }
        void size(const unsigned int size) { this->_size = size; }
#pragma endregion

#pragma region Actions
        void insert(T element, unsigned int index);
        void insert(T element) { append(element); }
        void push(T element);
        void append(T element);

        void remove();
        void remove(T element);
        void remove(unsigned int index);

        Node<T> *find(unsigned int index);
        Node<T> *find(T element);

        void sort() {}
#pragma endregion

    private:
        unsigned int _size;
        Node<T> *_first;
        Node<T> *_last;
    };
}
