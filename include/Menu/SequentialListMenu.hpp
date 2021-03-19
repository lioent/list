#include "Menu.hpp"
#include "Program/SequentialListProgram.hpp"

using namespace Header::Program;

namespace Header::Menu
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
