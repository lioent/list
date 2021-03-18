namespace Header_Model
{
    class BaseEntity
    {
    public:
        BaseEntity(unsigned int id = 0) { this->_id = id; }
        ~BaseEntity() {}

#pragma region GET;
        unsigned int getID() { return this->_id; }
#pragma endregion

    private:
        unsigned int _id;
    };
}
