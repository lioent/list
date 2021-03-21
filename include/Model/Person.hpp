#include <iostream>
#include "BaseEntity.hpp"

using std::string;

namespace Header::Model
{
    class Person : public BaseEntity
    {
    public:
        Person(string name = "", string rg = "");
        ~Person();

#pragma region GET; SET;
        string getName() const { return this->_name; }
        void setName(string const name) { this->_name = name; }

        string getRG() const { return this->_rg; }
        void setRG(string const rg) { this->_rg = rg; }
#pragma endregion

#pragma region Operator Oveload
        bool operator==(Person comparer);
#pragma endregion

    private:
        string _name;
        string _rg;
    };

}
