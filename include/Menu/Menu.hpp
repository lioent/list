#pragma once
#include "Util/List.hpp"
#include "MenuItem.hpp"

using namespace Header::Util;

namespace Header::Menu
{
    class Menu
    {
    public:
        Menu() {}
        ~Menu() {}

#pragma region Actions
        virtual void openMenu() {}
        virtual void exitMenu() {}
#pragma endregion

    protected:
        List<MenuItem> _items;
    };
}
