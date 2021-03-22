#pragma once

namespace Header::Util
{
    template <class T>
    class Node
    {
    public:
        Node(const T element);
        Node();
        ~Node();

#pragma region GET; SET;
        T element() const { return this->_element; }
        void element(const T element) { this->_element = element; }

        Node<T> *previous() { return this->_previous; }
        void previous(Node<T> *previous) { this->_previous = previous; }

        Node<T> *next() { return this->_next; }
        void next(Node<T> *next) { this->_next = next; }
#pragma endregion

#pragma region Operator Overload
        Node<T> &operator++();
        Node<T> operator++(int);
#pragma endregion

    private:
        T _element;
        Node<T> *_previous;
        Node<T> *_next;
    };
}
