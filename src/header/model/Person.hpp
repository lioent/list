#include <iostream>
#include "BaseEntity.hpp"

using std::string;

namespace Header_Model
{
    class Person : public BaseEntity
    {
    public:
        Person() {}
        ~Person() {}

#pragma region GET; SET;
        string getName() { return this->_name; }
        void setName(string name) { this->_name = name; }

        string getRG() { return this->_rg; }
        void setRG(string rg) { this->_rg = rg; }
#pragma endregion

    private:
        string _name;
        string _rg;
    };

}
