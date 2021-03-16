namespace header_util
{
    template <class T>
    class Node
    {
    public:
        Node() {}
        ~Node() {}

        /* ================== GET; SET; ================== */
        T *getElement() { return this->element; }
        Node<T> *getPrevious() { return this->previous; }
        Node<T> *getNext() { return this->next; }
        /* ===================== END ===================== */

        /* =================== Actions =================== */
        /* ===================== END ===================== */

        /* ============== Auxiliary Methods ============== */
        /* ===================== END ===================== */

    private:
        T *element;
        Node<T> *previous;
        Node<T> *next;
    };

} // namespace model_util
