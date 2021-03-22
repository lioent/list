#pragma once

#include "Menu.hpp"
#include "Menu/Enum/MenuOptionEnum.hpp"
#include "Menu/Enum/MenuInsertOptionEnum.hpp"
#include "Menu/Enum/RemoveMenuOptionEnum.hpp"

using namespace Header::Menu::Enum;

namespace Header::Menu
{
    class LinkedListMenu : public Menu
    {
    public:
        LinkedListMenu();
        ~LinkedListMenu();

#pragma region GET / SET
        MenuOptionEnum::MenuOption option() const
        {
            return this->_option;
        }
        void option(const MenuOptionEnum::MenuOption option) { this->_option = option; }

        InsertMenuOptionEnum::InsertMenuOption insertOption() const { return this->_insertOption; }
        void insertOption(InsertMenuOptionEnum::InsertMenuOption insertOption) { this->_insertOption = insertOption; }

        RemoveMenuOptionEnum::RemoveMenuOption removeOption() const { return this->_removeOption; }
        void removeOption(RemoveMenuOptionEnum::RemoveMenuOption removeOption) { this->_removeOption = removeOption; }
#pragma endregion

#pragma region Actions
        void openMenu();
        void exitMenu();

        // TO DO: make different menus for these methods
        void openInsertMenu();
        void openRemoveMenu();

        MenuOptionEnum::MenuOption readMenuOption();
        InsertMenuOptionEnum::InsertMenuOption readInsertMenuOption();
        RemoveMenuOptionEnum::RemoveMenuOption readRemoveMenuOption();
#pragma endregion

    private:
        MenuOptionEnum::MenuOption _option;
        InsertMenuOptionEnum::InsertMenuOption _insertOption;
        RemoveMenuOptionEnum::RemoveMenuOption _removeOption;
    };
}
