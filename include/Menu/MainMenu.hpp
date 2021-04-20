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

#pragma region GET / SET
        SequentialListMenu sequentialListMenu() const
        {
            return this->_sequentialListMenu;
        }

        LinkedListMenu linkedListMenu() const { return this->_linkedListMenu; }
#pragma endregion

#pragma region Actions
        void openMenu();
        void exitMenu();
#pragma endregion

    private:
        // sub menus
        SequentialListMenu _sequentialListMenu;
        LinkedListMenu _linkedListMenu;
    };
}
