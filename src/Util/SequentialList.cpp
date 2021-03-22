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
    for (int index = 0;
         index < this->size();
         index++)
    {
        delete (this->_list + index);
    }
}

#pragma region Actions
template <class T>
void Header::Util::SequentialList<T>::insert(T &element, unsigned int index)
{
    if (index > this->size())
        return;

    this->_size++;
    T *newList = new T[this->size()];

    // Copying values after index
    for (int idx = this->size() - 1;
         idx > index;
         idx--)
    {
        newList[idx] = this->_list[idx - 1];
    }

    newList[index] = element;

    // Copying values before index
    for (int idx = 0;
         idx < index;
         idx++)
    {
        newList[idx] = this->_list[idx];
    }

    delete (this->_list);
    this->_list = newList;
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
T Header::Util::SequentialList<T>::findAtIndex(unsigned int index)
{
}

template <class T>
T Header::Util::SequentialList<T>::find(T element)
{
}
#pragma endregion

template class Header::Util::SequentialList<Header::Model::Person>;
