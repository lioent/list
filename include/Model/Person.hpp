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
        void setName(const string name) { this->_name = name; }

        string getRG() const { return this->_rg; }
        void setRG(const string rg) { this->_rg = rg; }
#pragma endregion

#pragma region Operator Oveload
        bool operator==(const Person &comparer);
        void operator=(const Person &person);
#pragma endregion

    private:
        string _name;
        string _rg;
    };

}
