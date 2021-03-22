#pragma once

#include "Program/Program.hpp"
#include "Menu/SequentialListMenu.hpp"
#include "Util/SequentialList.hpp"
#include "Model/Person.hpp"

using namespace Header::Util;
using namespace Header::Menu;
using namespace Header::Model;

namespace Header::Program
{
    class SequentialListProgram : public Program
    {
    public:
        SequentialListProgram();
        ~SequentialListProgram();

#pragma region GET / SET
        SequentialListMenu *menu() const
        {
            return this->_sequentialListMenu;
        }

        SequentialList<Person> *list() const { return this->_list; }
        Person list(int index) const { return this->list()->list(index); }
#pragma endregion

#pragma region Actions
        void execute();
        void close();
#pragma endregion

#pragma region Auxiliary Methods
    private:
        // TO DO: make different menus for these methods
        void executeMainMenu();
        void executeInsertMenu();
        void executeRemoveMenu();
        void executeSearch();

        void printAllData();
        void printAllDataFromFile();

        Person createPerson();
        void printPerson(const Person person);
#pragma endregion

    private:
        SequentialListMenu *_sequentialListMenu;
        SequentialList<Person> *_list;
    };
}
