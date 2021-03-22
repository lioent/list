#pragma once

#include "Program/Program.hpp"
#include "Menu/LinkedListMenu.hpp"
#include "Util/List.hpp"
#include "Model/Person.hpp"

using namespace Header::Menu;
using namespace Header::Util;
using namespace Header::Model;

namespace Header::Program
{
    class LinkedListProgram : public Program
    {
    public:
        LinkedListProgram();
        ~LinkedListProgram();

#pragma region GET / SET
        LinkedListMenu *menu() const
        {
            return this->_linkedListMenu;
        }

        List<Person> *list() const { return this->_list; }

#pragma region Actions
        void execute();
        void close();
#pragma endregion

#pragma region Auxiliary Methods
    private:
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
        LinkedListMenu *_linkedListMenu;
        List<Person> *_list;
    };
}
