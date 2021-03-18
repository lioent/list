#include "Menu.hpp"
#include "Program/SequentialListProgram.hpp"

using namespace Header_Program;

namespace Header_Menu
{
    class SequentialListMenu : public Menu
    {
    public:
        SequentialListMenu() : Menu() {}
        ~SequentialListMenu() {}

#pragma region Actions

        void openMenu();
        void exitMenu();

#pragma endregion

    private:

        SequentialListProgram _sequentialListProgram;
    };
}
