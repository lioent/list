#include "SequentialList.hpp"

template <class T>
Header_Util::SequentialList<T>::SequentialList()
{
    this->_count = 0;
    this->_list = (T *)malloc(0);
}

template <class T>
Header_Util::SequentialList<T>::~SequentialList()
{
    free(this->_list);
}
