#include "Util/SequentialList.hpp"
#include "Model/Person.hpp"
#include <memory>
#include <cstdlib>

using namespace Header::Model;

using std::malloc;
using std::realloc;
using std::free;

template <class T>
Header::Util::SequentialList<T>::SequentialList()
{
    this->_count = 0;
    this->_list = (T *)malloc(0);
}

template <class T>
Header::Util::SequentialList<T>::~SequentialList()
{
    free(this->_list);
}

