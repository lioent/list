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

    int c = 4;
    Node<T> *auxiliar = find(index);
    Node<T> *newNode = new Node<T>(element);

    newNode->next(auxiliar);
    newNode->previous(auxiliar->previous());
    auxiliar->previous()->next(newNode);
    auxiliar->previous(newNode);

    ++this->_size;

    int m = 6;
    std::cout << "insert at index: " << c << " conditions and " << m << " assignments" << std::endl;
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

    int c = 1;

    Node<T> *newNode = new Node<T>(element);

    newNode->next(this->first());
    this->first()->previous(newNode);
    this->first(newNode);

    ++this->_size;

    int m = 5;
    std::cout << "push: " << c << " conditions and " << m << " assignments" << std::endl;
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

    int c = 1;

    Node<T> *newNode = new Node<T>(element);

    newNode->previous(this->last());
    this->last()->next(newNode);
    this->last(newNode);

    ++this->_size;

    int m = 5;
    std::cout << "insert element: " << c << " conditions and " << m << " assignments" << std::endl;
}

template <class T>
void Header::Util::List<T>::remove()
{
    if (this->size() == 0)
        return;

    if (this->size() == 1)
    {
        delete (this->first());
        this->first(nullptr);
        this->last(nullptr);
        this->_size = 0;
        return;
    }

    int c = 2;

    remove(this->last()->element());

    std::cout << "remove: " << c << " conditions" << std::endl;
}
template <class T>
void Header::Util::List<T>::remove(T element)
{
    if (this->size() == 0)
        return;

    this->_size--;
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

    int c = 3;

    nodeToBeRemoved->previous()->next(nodeToBeRemoved->next());
    nodeToBeRemoved->next()->previous(nodeToBeRemoved->previous());
    delete (nodeToBeRemoved);

    int m = 3;
    std::cout << "remove at index: " << c << " conditions and " << m << " assignments" << std::endl;

    return;
}
template <class T>
void Header::Util::List<T>::remove(unsigned int index)
{
    if (index >= this->size() || this->size() == 0)
        return;

    if (this->size() == 1)
    {
        delete (this->first());
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

    int c = 4;

    Node<T> *nodeToBeRemoved = find(index);
    nodeToBeRemoved->previous()->next(nodeToBeRemoved->next());
    nodeToBeRemoved->next()->previous(nodeToBeRemoved->previous());

    delete (nodeToBeRemoved);

    this->_size--;

    int m = 4;

    std::cout << "remove at index: " << c << " conditions and " << m << " assignments" << std::endl;
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

    int c = 3;
    int m = 0;

    Node<T> *iterator = this->first();
    for (unsigned int idx = 0;
         idx < index;
         idx++)
    {
        iterator = iterator->next();
        c++;
        m++;
    }

    std::cout << "find at index: " << c << " conditions and " << m << " assignments" << std::endl;
    return iterator;
}
// Finds the element in the list, if existing.
template <class T>
Header::Util::Node<T> *Header::Util::List<T>::find(T element)
{
    for (Node<T> *iterator = this->first();
         iterator != nullptr;
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
