#include "Program/MainProgram.hpp"

using std::cin;
using std::cout;
using std::endl;

Header::Program::MainProgram::MainProgram()
    : Program(),
      _mainMenu(),
      _sequentialListProgram(),
      _linkedListProgram()
{
}

Header::Program::MainProgram::~MainProgram()

{
}

#pragma region Actions
void Header::Program::MainProgram::execute()
{
    executeMainMenu();
}

void Header::Program::MainProgram::close()
{
}

void Header::Program::MainProgram::executeMainMenu()
{
    //this->menu().openMenu();
    // TO DO: open and read option from the menu using MainMenu class and enums
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
            this->sequentialListProgram().execute();
            break;

        case '2':
            this->linkedListProgram().execute();
            break;

        case ' ':
        case 'x':
        case 'X':
            exit = true;
            break;

        default:
            cout << "Invalid option" << endl;
            break;
        }
    } while (!exit);
}
#pragma endregion
