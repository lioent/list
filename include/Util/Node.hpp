#pragma once
#include <memory>

using std::unique_ptr;

namespace Header_Util
{
    template <class T>
    class Node
    {
    public:
        Node() {}
        ~Node() {}

#pragma region GET; SET;
        T *getElement() { return this->_element; }
        Node<T> *getPrevious() { return this->_previous; }
        Node<T> *getNext() { return this->_next; }
#pragma endregion

        Node<T> operator*();
        void operator++();
        bool operator!=(Node<T> node);

    private:
        T *_element;
        Node<T> *_previous;
        Node<T> *_next;
    };

}
