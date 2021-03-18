#include "Util/SequentialList.hpp"
#include "Model/Person.hpp"
#include <memory>
#include <cstdlib>

using namespace Header_Model;

using std::malloc;
using std::realloc;
using std::free;

#ifdef USE_EXPORT_KEYWORD
export
#endif

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

template class SequentialList<Person>;
