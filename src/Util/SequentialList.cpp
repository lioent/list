#include "Util/SequentialList.hpp"
#include "Model/Person.hpp"


template <class T>
Header::Util::SequentialList<T>::SequentialList()
{
}

template <class T>
Header::Util::SequentialList<T>::~SequentialList()
{
}

// template Header::Util::SequentialList<Header::Model::Person>::SequentialList();
// template Header::Util::SequentialList<Header::Model::Person>::~SequentialList();
template class Header::Util::SequentialList<Header::Model::Person>;
