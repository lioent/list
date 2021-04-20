#include "Util/SequentialList.hpp"
#include "Model/Person.hpp"

template <class T>
Header::Util::SequentialList<T>::SequentialList(T element)
{
    this->_size = 1;
    this->_list = new T[this->size()];
    this->_list[0] = element;
}

template <class T>
Header::Util::SequentialList<T>::SequentialList()
{
    this->_size = 0;
    this->_list = new T[this->size()];
}

template <class T>
Header::Util::SequentialList<T>::~SequentialList()
{
    delete[](this->_list);
}

#pragma region Actions
template <class T>
void Header::Util::SequentialList<T>::insert(T &element, unsigned int index)
{
    if (index > this->size())
        return;

    this->_size++;
    T *newList = new T[this->size()];

    int c = 1;
    int m = 2;

    // Copying values after index
    for (int idx = this->size() - 1;
         idx > index;
         idx--)
    {
        newList[idx] = this->_list[idx - 1];
        c++;
        m++;
    }

    newList[index] = element;

    m++;

    // Copying values before index
    for (int idx = 0;
         idx < index;
         idx++)
    {
        newList[idx] = this->_list[idx];
        c++;
        m++;
    }

    delete (this->_list);
    this->_list = newList;

    m++;

    std::cout << "insert at index: " << c << " conditions and " << m << " assignments" << std::endl;
}

template <class T>
void Header::Util::SequentialList<T>::push(T element)
{
}

template <class T>
void Header::Util::SequentialList<T>::append(T element)
{
}

template <class T>
void Header::Util::SequentialList<T>::remove(T element)
{
}

template <class T>
void Header::Util::SequentialList<T>::remove(unsigned int index)
{
    if (index > this->size() - 1 || this->size() == 0)
        return;

    if (this->size() == 1)
    {
        delete[](this->_list);
        this->size(0);
        this->_list = new T[this->size()];
        return;
    }

    int c = 2;

    this->_size--;
    T *newList = new T[this->size()];

    int m = 2;

    // Copying values after index
    for (int idx = this->size() - 1;
         idx >= index && idx < this->size();
         idx--)
    {
        newList[idx] = this->_list[idx + 1];
        c++;
        m++;
    }

    // Copying values before index
    for (int idx = 0;
         idx < index && idx < this->size();
         idx++)
    {
        newList[idx] = this->_list[idx];
        c++;
        m++;
    }

    delete (this->_list);
    this->_list = newList;
    m++;

    std::cout << "remove at index: " << c << " conditions and " << m << " assignments" << std::endl;
}

template <class T>
T Header::Util::SequentialList<T>::findAtIndex(unsigned int index)
{
    if (index > this->size() - 1)
        return T();

    return this->list(index);
}

template <class T>
T Header::Util::SequentialList<T>::find(T element)
{
    for (unsigned index = 0;
         index < this->size();
         index++)
    {
        if(element == this->list(index))
            return this->list(index);
    }

    return T();
}
#pragma endregion

template class Header::Util::SequentialList<Header::Model::Person>;
