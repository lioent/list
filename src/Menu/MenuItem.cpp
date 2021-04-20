#include "Menu/MenuItem.hpp"

Header::Menu::MenuItem::MenuItem(int key, string description)
{
    this->_key = key;
    this->_description = description;
}

Header::Menu::MenuItem::~MenuItem()
{
}

#pragma region Operator Overload
bool Header::Menu::MenuItem::operator==(MenuItem comparer)
{
    return (this->getDescription() == comparer.getDescription() && this->getKey() == comparer.getKey());
}
#pragma endregion
