namespace Header::Util
{
    template <class T>
    class SequentialList
    {
    public:
        SequentialList(T element);
        SequentialList();
        ~SequentialList();

#pragma region
        unsigned int size() const
        {
            return this->_size;
        }
        void size(const unsigned int size) { this->_size = size; }
#pragma endregion

#pragma region Actions
        void insert(T &element, unsigned int index);
        void insert(T element) { append(element); }
        void push(T element);
        void append(T element);

        void remove(T element) {}
        void pop(unsigned int index) {}
        void pop() { pop(this->size() - 1); }

        T findAtIndex(unsigned int index);
        T find(T element);

        void sort() {}
#pragma endregion

    private:
        unsigned int _size;
        T *_list;
    };
}
