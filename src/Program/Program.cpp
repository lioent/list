#include "Program/Program.hpp"

Header::Program::Program::Program()
{
    this->_fileManager = nullptr;
}

Header::Program::Program::~Program()
{
}

#pragma region Actions
void Header::Program::Program::waitForInput()
{
    fflush(stdin);
    std::cout << "Press Enter to continue...";
    int test = std::cin.get();
    fflush(stdin);
}
#pragma endregion
