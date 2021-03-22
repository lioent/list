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
#pragma endregion

#pragma region Auxiliary Methods
void Header::Program::SequentialListProgram::executeMainMenu()
{
    while (this->menu()->option() != MenuOptionEnum::exit)
    {
        this->menu()->openMenu();
        //this->menu().option(this->menu().readMenuOption());
        MenuOptionEnum::MenuOption option = this->menu()->readMenuOption();
        switch (option)
        {
        case MenuOptionEnum::exit:
            break;

        case MenuOptionEnum::insert:
            executeInsertMenu();
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
        {
            this->list()->insert(person, 0);
            break;
        }
        case InsertMenuOptionEnum::end:
        {
            this->list()->insert(person, this->list()->size());
            break;
        }
        case InsertMenuOptionEnum::index:
        {
            unsigned int index;
            cout << "What index do you want to insert the Person in (min: 0, max:" << this->list()->size() << "):";
            cin >> index;

            this->list()->insert(person, index);
            this->menu()->insertOption(InsertMenuOptionEnum::exit);
            break;
        }
        case InsertMenuOptionEnum::invalid:
        {
            std::cout << "Invalid option." << std::endl;

            break;
        }
        }
    }

    this->menu()->insertOption(InsertMenuOptionEnum::invalid);
}

void Header::Program::SequentialListProgram::close()
{
    delete (this->_list);
}

void Header::Program::SequentialListProgram::printAllData()
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
    string name;
    string rg;
    cout << "Enter the person name (enter empty to cancel):" << endl;
    cin >> name;
    fflush(stdin);

    if (name == " " || name == "\n")
        return Person();

    cout << "Enter the person RG: (enter empty to cancel)" << endl;
    cin >> rg;
    fflush(stdin);

    if (rg == " " || rg == "\n")
        return Person();

    return Person(name, rg);
}
#pragma endregion
