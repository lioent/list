#include "Program/SequentialListProgram.hpp"
#include "Menu/Enum/MenuOptionEnum.hpp"
#include "Menu/Enum/MenuInsertOptionEnum.hpp"
#include <sstream>

using namespace Header::Menu::Enum;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::stringstream;

Header::Program::SequentialListProgram::SequentialListProgram()
    : Header::Program::Program::Program()
{
    this->_list = new SequentialList<Person>();
    this->_sequentialListMenu = new SequentialListMenu();
}

Header::Program::SequentialListProgram::~SequentialListProgram()
{
}

#pragma region Actions
void Header::Program::SequentialListProgram::execute()
{
    this->_fileManager = new FileManager("Data/NomeRG10.txt");
    this->_list = new SequentialList<Person>{};

    executeMainMenu();
}

void Header::Program::SequentialListProgram::close()
{
    delete (this->_list);
}
#pragma endregion

#pragma region Auxiliary Methods
void Header::Program::SequentialListProgram::executeMainMenu()
{
    while (this->menu()->option() != MenuOptionEnum::exit)
    {
        this->menu()->openMenu();
        this->menu()->option(this->menu()->readMenuOption());

        switch (this->menu()->option())
        {
        case MenuOptionEnum::exit:
            break;

        case MenuOptionEnum::insert:
            executeInsertMenu();
            break;

        case MenuOptionEnum::remove:
            executeRemoveMenu();
            break;

        case MenuOptionEnum::search:
            executeSearch();
            break;

        case MenuOptionEnum::print:
            this->printAllData();

            waitForInput();
            this->menu()->openMenu();
            break;

        case MenuOptionEnum::invalid:
            std::cout << "Invalid option." << std::endl;
            break;
        }
    }

    this->menu()->option(MenuOptionEnum::invalid);
}

void Header::Program::SequentialListProgram::executeInsertMenu()
{
    Person person = createPerson();

    // TO DO: make an "isValid" method in "Person" class
    if (person.getName() == "" || person.getRG() == "")
        return;

    while (this->menu()->insertOption() != InsertMenuOptionEnum::exit)
    {
        this->menu()->openInsertMenu();
        this->menu()->insertOption(this->menu()->readInsertMenuOption());
        switch (this->menu()->insertOption())
        {
        case InsertMenuOptionEnum::exit:
            break;

        case InsertMenuOptionEnum::begin:
            this->list()->insert(person, 0);
            printAllData();

            this->menu()->insertOption(InsertMenuOptionEnum::exit);
            break;

        case InsertMenuOptionEnum::end:
            this->list()->insert(person, this->list()->size());
            printAllData();

            this->menu()->insertOption(InsertMenuOptionEnum::exit);
            break;

        case InsertMenuOptionEnum::index:
            fflush(stdin);
            unsigned int index;
            cout << "What index do you want to insert the Person in (min: 0, max: " << this->list()->size() << "):";
            cin >> index;
            fflush(stdin);

            this->list()->insert(person, index);
            printAllData();

            this->menu()->insertOption(InsertMenuOptionEnum::exit);
            break;

        case InsertMenuOptionEnum::invalid:
            cout << "Invalid option." << endl;

            break;
        }
    }

    this->menu()->insertOption(InsertMenuOptionEnum::invalid);
}

void Header::Program::SequentialListProgram::executeRemoveMenu()
{
    while (this->menu()->removeOption() != RemoveMenuOptionEnum::exit)
    {
        this->menu()->openRemoveMenu();
        this->menu()->removeOption(this->menu()->readRemoveMenuOption());
        switch (this->menu()->removeOption())
        {
        case RemoveMenuOptionEnum::exit:
            break;

        case RemoveMenuOptionEnum::begin:
            this->list()->remove(0);
            printAllData();
            this->menu()->removeOption(RemoveMenuOptionEnum::exit);

            break;

        case RemoveMenuOptionEnum::end:
            this->list()->remove();
            printAllData();
            this->menu()->removeOption(RemoveMenuOptionEnum::exit);

            break;

        case RemoveMenuOptionEnum::index:
            fflush(stdin);
            unsigned int index;
            cout << "What index do you want to remove the Person from (min: 0, max: " << this->list()->size() - 1 << "):";
            cin >> index;
            fflush(stdin);

            this->list()->remove(index);
            printAllData();
            this->menu()->removeOption(RemoveMenuOptionEnum::exit);
            break;

        case RemoveMenuOptionEnum::invalid:
            cout << "Invalid option." << endl;
            break;
        }
    }
    this->menu()->removeOption(RemoveMenuOptionEnum::invalid);
}

void Header::Program::SequentialListProgram::executeSearch()
{
    fflush(stdin);
    unsigned int index;
    cout << "Enter an index to look into: (min: 0, max: " << this->list()->size() - 1 << "):";
    cin >> index;
    fflush(stdin);

    if (index > this->list()->size() - 1)
    {
        cout << "Invalid index" << endl;
        return;
    }

    Person person = this->list()->findAtIndex(index);
    // TO DO: make an "isValid" method in "Person" class
    if (person.getName() == "" || person.getRG() == "")
    {
        cout << "Not found." << endl;
        return;
    }

    printPerson(person);
}

void Header::Program::SequentialListProgram::printAllData()
{
    for (int index = 0;
         index < this->list()->size();
         index++)
    {
        Person person = this->list(index);
        printPerson(person);
    }
}

void Header::Program::SequentialListProgram::printAllDataFromFile()
{
    List<string> dataSet = this->_fileManager->readData();

    for (Node<string> *iterator = dataSet.getFirst();
         iterator != dataSet.getLast();
         iterator = iterator->getNext())
    {
        string data[2] = {"", ""};
        stringstream string_stream(iterator->getElement());
        for (int i = 0;
             string_stream.good() && i < 2;
             i++)
        {
            string line;
            getline(string_stream, line, ',');
            data[i] = line;
        }

        string name = data[0];
        string rg = data[1];

        Person person = Person(name, rg);
        cout << "Name: " << person.getName() << " - RG: " << person.getRG() << endl;
    }
}

Person Header::Program::SequentialListProgram::createPerson()
{
    fflush(stdin);

    string name;
    string rg;
    cout << "Enter the person name (enter empty to cancel):" << endl;
    getline(cin, name);
    fflush(stdin);

    // TO DO: make an "nameIsValid" method in "Person" class
    if (name == "" || name == " " || name == "\n")
        return Person();

    cout << "Enter the person RG: (enter empty to cancel)" << endl;
    cin >> rg;
    fflush(stdin);

    // TO DO: make an "rgIsValid" method in "Person" class
    if (rg == "" || rg == " " || rg == "\n")
        return Person();

    return Person(name, rg);
}

void Header::Program::SequentialListProgram::printPerson(const Person person)
{
    cout << "Name: " << person.getName()
         << " - RG: " << person.getRG()
         << endl;
}
#pragma endregion
