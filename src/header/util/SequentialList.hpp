namespace Header_Util
{
    template <class T>
    class SequentialList
    {
        public:
        SequentialList();
        ~SequentialList();

#pragma region Actions
        void insert(unsigned int index, T element);
        void insert(T element) { insert(this->_size, element); }

        void remove(unsigned int index);
        void remove(T element) { remove(this->_size - 1); }

        void sort();
#pragma endregion

        private:
        T* _list;
        unsigned int _size;
    };
}
