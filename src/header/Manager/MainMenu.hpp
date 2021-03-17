#include "Menu.hpp"

namespace Header_Manager
{
    class MainMenu : public Menu
    {
    public:
        MainMenu();
        ~MainMenu();

        void openMenu();
        void exitMenu();

    private: 
        // sub menus
        SequentialListMenu _sequentialListMenu;
        LinkedListMenu _LinkedListMenu;
        
    };
}