#include "Menu/SequentialListMenu.hpp"

using std::cout;
using std::cin;
using std::endl;

void Header_Menu::SequentialListMenu::openMenu()
{
    bool exit = false;
    do
    {
        char option = ' ';
        cout << "Select what list type you wanna work with:" << endl;
        cout << "1. Print all data on the screen" << endl;
        cout << "X. Exit" << endl;
        cin >> option;

        switch (option)
        {
        case '1':
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