#include "Util/List.hpp"
#include "Model/Person.hpp"
#include "Menu/MenuItem.hpp"

// Initializes the list with a given element already inserted.
template <class T>
Header::Util::List<T>::List(T element)
{
    initializeList();
    insertFirstElement(element);
}

// Initializes an empty list.
template <class T>
Header::Util::List<T>::List()
{
    initializeList();
}

// Deallocates every element in the list.
template <class T>
Header::Util::List<T>::~List()
{
    Node<T> *current = this->getFirst();
    while (current != nullptr)
    {
        Node<T> *next = current->getNext();
        delete (current);
        current = next;
    }
}

#pragma region Actions
// Inserts an element at a given index or at the end of the list.
template <class T>
void Header::Util::List<T>::insert(T element, unsigned int index)
{
    if (index > this->getSize())
        return;

    if (this->getSize() == 0)
    {
        insertFirstElement(element);
        return;
    }

    if (index == 0)
    {
        push(element);
        return;
    }

    if (index == this->getSize())
    {
        append(element);
        return;
    }

    Node<T> *auxiliar = findAtIndex(index);
    Node<T> *newNode = new Node<T>(element);

    newNode->setPrevious(auxiliar->getPrevious());
    newNode->setNext(auxiliar);
    auxiliar->setPrevious(newNode);

    ++this->_size;
}

// Inserts an element at the beginning of the list.
template <class T>
void Header::Util::List<T>::push(T element)
{
    if (this->getSize() == 0)
    {
        insertFirstElement(element);
        return;
    }

    Node<T> *newNode = new Node<T>(element);

    newNode->setNext(this->getFirst());
    this->getFirst()->setPrevious(newNode);
    this->setFirst(newNode);

    ++this->_size;
}

// Inserts an element at the end of the list.
template <class T>
void Header::Util::List<T>::append(T element)
{
    if (this->getSize() == 0)
    {
        insertFirstElement(element);
        return;
    }

    Node<T> *newNode = new Node<T>(element);

    newNode->setPrevious(this->getLast());
    this->getLast()->setNext(newNode);
    this->setLast(newNode);

    ++this->_size;
}

// Finds the element at the given index.
template <class T>
Header::Util::Node<T> *Header::Util::List<T>::findAtIndex(unsigned int index)
{
    if (index > this->getSize())
        return nullptr;

    Node<T> *iterator = this->getFirst();
    for (unsigned int idx = 0;
         idx != index;
         idx++)
    {
        iterator = iterator->getNext();
    }

    return iterator;
}

// Finds the element in the list, if existing.
template <class T>
Header::Util::Node<T> *Header::Util::List<T>::find(T element)
{

    for (Node<T> *iterator = this->getFirst();
         iterator != this->getLast()->getNext();
         iterator++)
    {
        if (iterator->getElement() == element)
            return iterator;
    }

    return nullptr;
}
#pragma endregion

#pragma region Auxiliary Methods
template <class T>
void Header::Util::List<T>::initializeList()
{
    this->_size = 0;
    this->_first = nullptr;
    this->_last = nullptr;
}

template <class T>
void Header::Util::List<T>::insertFirstElement(T element)
{
    Node<T> *newNode = new Node<T>(element);

    this->setFirst(newNode);
    this->setLast(newNode);
    this->_size = 1;
}
#pragma endregion

template class Header::Util::List<Header::Model::Person>;
template class Header::Util::List<Header::Menu::MenuItem>;
template class Header::Util::List<std::string>;
