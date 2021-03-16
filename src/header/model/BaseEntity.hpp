namespace header_model
{
    class BaseEntity
    {
    public:
        BaseEntity(unsigned int id = 0) { this->id = id; }
        ~BaseEntity() { }

        /* ================== GET; SET; ================== */
        unsigned int getID() { return this->id; }
        /* ===================== END ===================== */

    private:
        unsigned int id;
    }
    
} // namespace header_model
