#include "Menu/SequentialListMenu.hpp"

using std::cin;
using std::cout;
using std::endl;

Header::Menu::SequentialListMenu::SequentialListMenu()
    : Header::Menu::Menu::Menu()
{
    this->_option = MenuOptionEnum::invalid;
    this->_insertOption = InsertMenuOptionEnum::invalid;
}

Header::Menu::SequentialListMenu::~SequentialListMenu()
{
}

#pragma region Actions
void Header::Menu::SequentialListMenu::openMenu()
{

    cout << "Select what operation you wanna execute:" << endl;
    cout << "1. Insert person" << endl;
    cout << "2. Print all data on the screen" << endl;
    cout << "X. Exit" << endl;
}

void Header::Menu::SequentialListMenu::exitMenu()
{
}

void Header::Menu::SequentialListMenu::openInsertMenu()
{
    cout << "Where do you want to insert data:" << endl;
    cout << "1. In the beginning" << endl;
    cout << "2. In the end" << endl;
    cout << "3. At index" << endl;
    cout << "X. Exit" << endl;
}

void Header::Menu::SequentialListMenu::openRemoveMenu()
{
    cout << "Not implemented yet." << endl;
}

Header::Menu::Enum::MenuOptionEnum::MenuOption Header::Menu::SequentialListMenu::readMenuOption()
{
    char option = ' ';
    fflush(stdin);
    cin >> option;

    switch (option)
    {
    case MenuOptionEnum::insert:
        this->option(MenuOptionEnum::insert);
        return MenuOptionEnum::insert;
        break;

    case MenuOptionEnum::print:
        this->option(MenuOptionEnum::print);
        return MenuOptionEnum::print;
        break;

    case ' ':
    case 'x':
    case 'X':
        this->option(MenuOptionEnum::exit);
        return MenuOptionEnum::exit;
        break;

    default:
        this->option(MenuOptionEnum::invalid);
        return MenuOptionEnum::insert;
        break;
    }
}

Header::Menu::Enum::InsertMenuOptionEnum::InsertMenuOption Header::Menu::SequentialListMenu::readInsertMenuOption()
{
    char option = ' ';
    fflush(stdin);
    cin >> option;

    switch (option)
    {
    case InsertMenuOptionEnum::begin:
        this->insertOption(InsertMenuOptionEnum::begin);
        return InsertMenuOptionEnum::begin;
        break;

    case InsertMenuOptionEnum::end:
        this->insertOption(InsertMenuOptionEnum::end);
        return InsertMenuOptionEnum::end;
        break;

    case InsertMenuOptionEnum::index:
        this->insertOption(InsertMenuOptionEnum::index);
        return InsertMenuOptionEnum::index;
        break;

    case ' ':
    case 'x':
    case 'X':
        this->insertOption(InsertMenuOptionEnum::exit);
        return InsertMenuOptionEnum::exit;
        break;

    default:
        this->insertOption(InsertMenuOptionEnum::invalid);
        return InsertMenuOptionEnum::invalid;
        break;
    }
}
#pragma endregion
