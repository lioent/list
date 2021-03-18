#pragma once
#include "../Util/List.hpp"
#include "MenuItem.hpp"

using namespace Header_Util;

namespace Header_Menu
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

#pragma region Auxiliary Methods
    protected:
        void waitForInput();
#pragma endregion

    protected:
        List<MenuItem> _items;
    };
}
