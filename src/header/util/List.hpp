#include "Node.hpp"

using std::unique_ptr;

namespace Header_Util
{
    template <class T>
    class List
    {
    public:
        List() {}
        ~List() {}

#pragma region GET / SET
        Node<T> *getFirst() { return this->first->_getElement(); }
        Node<T> *getLast() { return this->first->_getElement(); }
        unsigned int getSize() { return this->_size; }
#pragma endregion

#pragma region Actions
        void insert(unsigned int index, T *element);
        void insert(T *element) { insert(0, element); }

        void remove(unsigned int index);
        void remove(T *element) { remove(length - 1); }

        void sort();
#pragma endregion

// #pragma region Auxiliary Methods
//         iterator begin() { return &this->_first; }
//         const_iterator begin() const { return &this->_first; }
//         iterator end() { return &this->_last; }
//         const_iterator end() const { return &this->_last; }
// #pragma endregion

    private:
        Node<T>* _element;
        Node<T>* _first;
        Node<T>* _last;
        unsigned int _size;

    };
}
