#include "Menu.hpp"
#include "SequentialListMenu.hpp"
#include "LinkedListMenu.hpp"

namespace Header::Menu
{
    class MainMenu : public Menu
    {
    public:
        MainMenu();
        ~MainMenu();

#pragma region Actions
        void openMenu();
        void exitMenu();
#pragma endregion

    private:
        // sub menus
        SequentialListMenu *_sequentialListMenu;
        LinkedListMenu *_linkedListMenu;
    };
}
