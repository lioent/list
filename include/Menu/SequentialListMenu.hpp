#pragma once

#include "Menu.hpp"
#include "Menu/Enum/MenuInsertOptionEnum.hpp"
#include "Menu/Enum/MenuOptionEnum.hpp"

using namespace Header::Menu::Enum;

namespace Header::Menu
{
    class SequentialListMenu : public Menu
    {
    public:
        SequentialListMenu();
        ~SequentialListMenu();

#pragma region GET / SET
        MenuOptionEnum::MenuOption option() const
        {
            return this->_option;
        }

        void option(const MenuOptionEnum::MenuOption option) { this->_option = option; }

        InsertMenuOptionEnum::InsertMenuOption insertOption() const { return this->_insertOption; }
        void insertOption(InsertMenuOptionEnum::InsertMenuOption insertOption) { this->_insertOption = insertOption; }
#pragma endregion

#pragma region Actions
        void openMenu();
        void exitMenu();

        // TO DO: make different menus for these methods
        void openInsertMenu();
        void openRemoveMenu();

        MenuOptionEnum::MenuOption readMenuOption();
        InsertMenuOptionEnum::InsertMenuOption readInsertMenuOption();
#pragma endregion

    private:
        MenuOptionEnum::MenuOption _option;
        InsertMenuOptionEnum::InsertMenuOption _insertOption;
    };
}

