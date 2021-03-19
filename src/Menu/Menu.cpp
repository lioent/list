#include "Menu/Menu.hpp"

#include <iostream>

using std::string;
using std::cout;
using std::cin;

#pragma region Auxiliary Methods
void Header::Menu::Menu::waitForInput()
{
    cout << "Press Enter to continue...";
    cin.get();
    cin.clear();
}
#pragma endregion
