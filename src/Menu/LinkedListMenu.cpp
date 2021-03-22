#include "Menu/LinkedListMenu.hpp"

using std::cin;
using std::cout;
using std::endl;

Header::Menu::LinkedListMenu::LinkedListMenu()
    : Header::Menu::Menu::Menu()
{
    this->_option = MenuOptionEnum::invalid;
    this->_insertOption = InsertMenuOptionEnum::invalid;
    this->_removeOption = RemoveMenuOptionEnum::invalid;
}

Header::Menu::LinkedListMenu::~LinkedListMenu()
{
}

#pragma region Actions
void Header::Menu::LinkedListMenu::openMenu()
{
    cout << "Select what operation you wanna execute:" << endl;
    cout << "1. Insert person" << endl;
    cout << "2. Remove person" << endl;
    cout << "3. Find person" << endl;
    cout << "4. Print people" << endl;
    cout << "5. Save current data in File" << endl;
    cout << "6. Load data from File" << endl;
    cout << "X. Exit" << endl;
}
void Header::Menu::LinkedListMenu::exitMenu()
{
}

void Header::Menu::LinkedListMenu::openInsertMenu()
{
    cout << "Where do you want to insert data:" << endl;
    cout << "1. In the beginning" << endl;
    cout << "2. In the end" << endl;
    cout << "3. At index" << endl;
    cout << "X. Exit" << endl;
}
void Header::Menu::LinkedListMenu::openRemoveMenu()
{
    cout << "Where do you want to remove the data from:" << endl;
    cout << "1. From the beginning" << endl;
    cout << "2. From the end" << endl;
    cout << "3. From index" << endl;
    cout << "X. Exit" << endl;
}

Header::Menu::Enum::MenuOptionEnum::MenuOption Header::Menu::LinkedListMenu::readMenuOption()
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

    case MenuOptionEnum::remove:
        this->option(MenuOptionEnum::remove);
        return MenuOptionEnum::remove;
        break;

    case MenuOptionEnum::search:
        this->option(MenuOptionEnum::search);
        return MenuOptionEnum::search;
        break;

    case MenuOptionEnum::print:
        this->option(MenuOptionEnum::print);
        return MenuOptionEnum::print;
        break;

    case MenuOptionEnum::save:
        this->option(MenuOptionEnum::save);
        return MenuOptionEnum::save;
        break;
        
    case MenuOptionEnum::load:
        this->option(MenuOptionEnum::load);
        return MenuOptionEnum::load;
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
Header::Menu::Enum::InsertMenuOptionEnum::InsertMenuOption Header::Menu::LinkedListMenu::readInsertMenuOption()
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
Header::Menu::Enum::RemoveMenuOptionEnum::RemoveMenuOption Header::Menu::LinkedListMenu::readRemoveMenuOption()
{
    char option = ' ';
    fflush(stdin);
    cin >> option;

    switch (option)
    {
    case RemoveMenuOptionEnum::begin:
        this->removeOption(RemoveMenuOptionEnum::begin);
        return RemoveMenuOptionEnum::begin;
        break;

    case RemoveMenuOptionEnum::end:
        this->removeOption(RemoveMenuOptionEnum::end);
        return RemoveMenuOptionEnum::end;
        break;

    case RemoveMenuOptionEnum::index:
        this->removeOption(RemoveMenuOptionEnum::index);
        return RemoveMenuOptionEnum::index;
        break;

    case ' ':
    case 'x':
    case 'X':
        this->removeOption(RemoveMenuOptionEnum::exit);
        return RemoveMenuOptionEnum::exit;
        break;

    default:
        this->removeOption(RemoveMenuOptionEnum::invalid);
        return RemoveMenuOptionEnum::invalid;
        break;
    }
}
