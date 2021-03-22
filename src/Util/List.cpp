#include "Util/List.hpp"
#include "Model/Person.hpp"
#include "Menu/MenuItem.hpp"

// Initializes the list with a given element already inserted.
template <class T>
Header::Util::List<T>::List(T element)
{
    Node<T> *newNode = new Node<T>(element);

    this->_first = newNode;
    this->_last = newNode;
    this->_size = 1;
}

// Initializes an empty list.
template <class T>
Header::Util::List<T>::List()
{
    this->_size = 0;
    this->_first = nullptr;
    this->_last = nullptr;
}

// Deallocates every element in the list.
template <class T>
Header::Util::List<T>::~List()
{
    Node<T> *current = this->first();
    while (current != nullptr)
    {
        Node<T> *next = current->next();
        delete (current);
        current = next;
    }
}

#pragma region Actions
// Inserts an element at a given index or at the end of the list.
template <class T>
void Header::Util::List<T>::insert(T element, unsigned int index)
{
    if (index > this->size())
        return;

    if (this->size() == 0)
    {
        Node<T> *newNode = new Node<T>(element);

        this->_first = newNode;
        this->_last = newNode;
        this->_size = 1;
        return;
    }

    if (index == 0)
    {
        push(element);
        return;
    }

    if (index == this->size())
    {
        append(element);
        return;
    }

    Node<T> *auxiliar = find(index);
    Node<T> *newNode = new Node<T>(element);

    newNode->next(auxiliar);
    newNode->previous(auxiliar->previous());
    auxiliar->previous()->next(newNode);
    auxiliar->previous(newNode);

    ++this->_size;
}
// Inserts an element at the beginning of the list.
template <class T>
void Header::Util::List<T>::push(T element)
{
    if (this->size() == 0)
    {
        Node<T> *newNode = new Node<T>(element);

        this->_first = newNode;
        this->_last = newNode;
        this->_size = 1;
        return;
    }

    Node<T> *newNode = new Node<T>(element);

    newNode->next(this->first());
    this->first()->previous(newNode);
    this->first(newNode);

    ++this->_size;
}
// Inserts an element at the end of the list.
template <class T>
void Header::Util::List<T>::append(T element)
{
    if (this->size() == 0)
    {
        Node<T> *newNode = new Node<T>(element);

        this->_first = newNode;
        this->_last = newNode;
        this->_size = 1;
        return;
    }

    Node<T> *newNode = new Node<T>(element);

    newNode->previous(this->last());
    this->last()->next(newNode);
    this->last(newNode);

    ++this->_size;
}


template <class T>
void Header::Util::List<T>::remove()
{
    if(this->size() == 0)
        return;

    remove(this->last()->element());
}
template <class T>
void Header::Util::List<T>::remove(T element)
{
    if(this->size() == 0)
        return;

    this->_size--;
    // find element
    Node<T> *nodeToBeRemoved = find(element);

    if (nodeToBeRemoved->element() == this->first()->element())
    {
        this->first(nodeToBeRemoved->next());
        delete (this->first()->previous());
        return;
    }
    if (nodeToBeRemoved->element() == this->last()->element())
    {
        this->last(nodeToBeRemoved->previous());
        delete (this->last()->next());
        return;
    }

    nodeToBeRemoved->previous()->next(nodeToBeRemoved->next());
    nodeToBeRemoved->next()->previous(nodeToBeRemoved->previous());
    delete (nodeToBeRemoved);

    return;
}

template <class T>
void Header::Util::List<T>::remove(unsigned int index)
{
    if (index >= this->size() || this->size() == 0)
        return;

    if(this->size() == 1)
    {
        delete(this->first());
        this->first(nullptr);
        this->last(nullptr);
        this->_size--;
        return;
    }

    if (index == 0)
    {
        this->first(this->first()->next());
        delete (this->first()->previous());
        this->_size--;
        return;
    }

    if (index == this->size() - 1)
    {
        this->first(this->first()->previous());
        delete (this->first()->next());
        this->_size--;
        return;
    }

    Node<T> *nodeToBeRemoved = find(index);
    nodeToBeRemoved->previous()->next(nodeToBeRemoved->next());
    nodeToBeRemoved->next()->previous(nodeToBeRemoved->previous());

    delete (nodeToBeRemoved);

    this->_size--;
}

// Finds the element at the given index.
template <class T>
Header::Util::Node<T> *Header::Util::List<T>::find(unsigned int index)
{
    if (index >= this->size())
        return nullptr;

    if (index == 0)
        return this->first();

    if (index == this->size() - 1)
        return this->last();

    Node<T> *iterator = this->first();
    for (unsigned int idx = 0;
         idx < index;
         idx++)
    {
        iterator = iterator->next();
    }

    return iterator;
}
// Finds the element in the list, if existing.
template <class T>
Header::Util::Node<T> *Header::Util::List<T>::find(T element)
{
    for (Node<T> *iterator = this->first();
         iterator != this->last()->next();
         iterator = iterator->next())
    {
        if (iterator->element() == element)
            return iterator;
    }

    return nullptr;
}
#pragma endregion

template class Header::Util::List<Header::Model::Person>;
template class Header::Util::List<Header::Menu::MenuItem>;
template class Header::Util::List<std::string>;
