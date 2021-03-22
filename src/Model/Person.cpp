#include "Model/Person.hpp"

Header::Model::Person::Person(string name, string rg)
    : BaseEntity()
{
    this->_name = name;
    this->_rg = rg;
}

Header::Model::Person::~Person()
{
}

#pragma region Operator Overload
bool Header::Model::Person::operator==(const Person &comparer)
{
    return (this->getName() == comparer.getName() && this->getRG() == comparer.getRG());
}

void Header::Model::Person::operator=(const Person &person)
{
    try
    {
        string name = person.getName();
        string rg = person.getRG();
        this->setName(name);
        this->setRG(rg);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
#pragma endregion
