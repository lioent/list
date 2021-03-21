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
bool Header::Model::Person::operator==(Person comparer)
{
    return (this->getName() == comparer.getName() && this->getRG() == comparer.getRG());
}

#pragma endregion
