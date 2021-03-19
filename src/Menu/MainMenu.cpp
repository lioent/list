#include "Menu/MainMenu.hpp"
#include "Util/Node.hpp"
#include <iostream>


using std::cin;
using std::cout;
using std::endl;

using namespace Header::Util;

Header::Menu::MainMenu::MainMenu()
{
    openMenu();
}

Header::Menu::MainMenu::~MainMenu()
{
    exitMenu();
}

#pragma region Actions
void Header::Menu::MainMenu::openMenu()
{
    bool exit = false;
    do
    {
        char option = ' ';
        cout << "Select what list type you wanna work with:" << endl;
        cout << "1. Sequential List" << endl;
        cout << "2. Linked List" << endl;
        cout << "X. Exit" << endl;
        cin >> option;

        switch (option)
        {
        case '1':
            this->_sequentialListMenu = new SequentialListMenu();
            this->_sequentialListMenu->openMenu();
            delete (this->_sequentialListMenu);
            break;

        case '2':
            // this->_linkedListMenu = new LinkedListMenu();
            // this->_linkedListMenu->openMenu();
            // free(this->_sequentialListMenu);
            cout << "Not implemeted yet." << endl;
            waitForInput();
            break;

        case ' ':
        case 'x':
        case 'X':
            exit = true;
            break;

        default:
            cout << "Invalid option" << endl;
            waitForInput();
            break;
        }
    } while (!exit);
}

void Header::Menu::MainMenu::exitMenu()
{
    
}
#pragma endregion
