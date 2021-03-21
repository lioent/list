#include "Util/Node.hpp"
#include "Model/Person.hpp"
#include "Menu/MenuItem.hpp"

template <class T>
Header::Util::Node<T>::Node(const T element)
    : _element(element)
{
    this->_previous = nullptr;
    this->_next = nullptr;
}

template <class T>
Header::Util::Node<T>::Node()
    : _element()
{
    this->_previous = nullptr;
    this->_next = nullptr;
}

template <class T>
Header::Util::Node<T>::~Node()
{
}

#pragma region Operator Overload
template <class T>
Header::Util::Node<T> &Header::Util::Node<T>::operator++()
{
    *this = *this->getNext();
    return *this;
}
template <class T>
Header::Util::Node<T> Header::Util::Node<T>::operator++(int)
{
    Node<T> old = *this;
    operator++();
    return old;
}
#pragma endregion

template class Header::Util::Node<Header::Model::Person>;
template class Header::Util::Node<Header::Menu::MenuItem>;
template class Header::Util::Node<std::string>;
