#include "Program/Program.hpp"
#include "Menu/MainMenu.hpp"
#include "Program/SequentialListProgram.hpp"
#include "Program/LinkedListProgram.hpp"

using namespace Header::Menu;

namespace Header::Program
{
    class MainProgram : public Program
    {
    public:
        MainProgram();
        ~MainProgram();

#pragma region GET / SET
        MainMenu menu() const
        {
            return this->_mainMenu;
        }

        SequentialListProgram sequentialListProgram() const { return this->_sequentialListProgram; }
        LinkedListProgram linkedListProgram() const { return this->_linkedListProgram;}
#pragma endregion

#pragma region Actions
        void execute();
        void close();

        void executeMainMenu();
#pragma endregion

    private:
        MainMenu _mainMenu;
        SequentialListProgram _sequentialListProgram;
        LinkedListProgram _linkedListProgram;
    };
}
