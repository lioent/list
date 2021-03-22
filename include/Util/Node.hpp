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
        T getElement() const { return this->_element; }
        void setElement(const T element) { this->_element = element; }

        Node<T> *getPrevious() { return this->_previous; }
        void setPrevious(Node<T> *previous) { this->_previous = previous; }

        Node<T> *getNext() { return this->_next; }
        void setNext(Node<T> *next) { this->_next = next; }
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
