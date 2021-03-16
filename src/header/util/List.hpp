#include "Node.hpp"

namespace header_util
{
    template <class T>
    class List
    {
    public:
        List() { }
        ~List() { }

        /* ================== GET; SET; ================== */
        T *getFirst() { return this->first->getElement(); }
        T *getLast() { return this->first->getElement(); }
        unsigned int getCount() { return this->count; }
        /* ===================== END ===================== */

        /* =================== Actions =================== */
        void insert(unsigned int index, T *element);
        void insert(T *element) { insert(0, element); }

        void remove(unsigned int index);
        void remove(T *element) { remove(length - 1); }

        void sort();
        /* ===================== END ===================== */

        /* ============== Auxiliary Methods ============== */
        /* ===================== END ===================== */

    private:
        Node<T> *first;
        Node<T> *last;
        unsigned int count;
    };

} // namespace util_header
