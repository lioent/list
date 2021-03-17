#include <iostream>
#include "../Util/List.hpp"
#include "MenuItem.hpp"

using std::string;

using namespace Header_Util;

namespace Header_Manager
{
    class Menu
    {
    public:
        Menu();
        ~Menu();

#pragma region Actions
        virtual void openMenu();
        virtual void exitMenu();
#pragma endregion

    protected:
        List<MenuItem> _items;
    };
}