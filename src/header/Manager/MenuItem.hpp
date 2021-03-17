#include <iostream>

using std::string;

namespace Header_Manager
{
    class MenuItem
    {
    public:
#pragma region GET; SET;
        int getKey()
        {
            return this->_key;
        }
        void setKey(int key) { this->_key = key; }

        string getDescription() { return this->_description; }
        void setDescription(string description) { this->_description = description; }
#pragma endregion

    private:
        int _key;
        string _description;
    };

}
