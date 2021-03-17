#include "MainMenu.hpp"

#include <iostream>
#include "Node.hpp"

using std::cin;
using std::cout;
using std::endl;

using namespace Header_Util;

Header_Manager::MainMenu::MainMenu()
{
    openMenu();
}

Header_Manager::MainMenu::~MainMenu()
{
    exitMenu();
}

#pragma region Actions

void Header_Manager::MainMenu::openMenu()
{
    char option = ' ';
    while (option != '3')
    {
        cout << "Select what list type you wanna work with:" << endl;
        cout << "1. Sequential List" << endl;
        cout << "2. Linked List" << endl;
        cout << "3. Exit" << endl;
        cin >> option;

        switch(option)
        {
            case '1':
            break;

            case '2':
            break;

            case '3':
            break;

            default:
            cout << "Invalid option" << endl;
            break;
        }
    }
}

#pragma endregion
