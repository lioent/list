#include "Program/LinkedListProgram.hpp"
#include "Menu/Enum/MenuOptionEnum.hpp"
#include "Menu/Enum/MenuInsertOptionEnum.hpp"
#include "Menu/Enum/RemoveMenuOptionEnum.hpp"
#include <sstream>
#include <chrono>

using namespace Header::Menu::Enum;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::stringstream;

Header::Program::LinkedListProgram::LinkedListProgram()
    : Header::Program::Program()
{
    this->_list = nullptr;
    this->_linkedListMenu = nullptr;
}
Header::Program::LinkedListProgram::~LinkedListProgram()
{
    delete (this->_list);
    delete (this->_linkedListMenu);
}

#pragma region Actions
void Header::Program::LinkedListProgram::execute()
{
    this->_fileManager = new FileManager("Data/NomeRG10.txt");
    this->_list = new List<Person>();
    this->_linkedListMenu = new LinkedListMenu();

    executeMainMenu();
}
void Header::Program::LinkedListProgram::close()
{
    delete (this->_list);
    delete (this->_linkedListMenu);
}
#pragma endregion

#pragma region AuxiliaryMethods
void Header::Program::LinkedListProgram::executeMainMenu()
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
            break;

        case MenuOptionEnum::save:
            executeSaveFile();
            break;

        case MenuOptionEnum::load:
            executeLoadFile();
            break;

        case MenuOptionEnum::invalid:
            std::cout << "Invalid option." << std::endl;
            break;
        }
    }

    this->menu()->option(MenuOptionEnum::invalid);
}
void Header::Program::LinkedListProgram::executeInsertMenu()
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
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            this->list()->push(person);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
            std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;

            printAllData();

            this->menu()->insertOption(InsertMenuOptionEnum::exit);
            break;
        }

        case InsertMenuOptionEnum::end:
        {
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            this->list()->append(person);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
            std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;

            printAllData();
            this->menu()->insertOption(InsertMenuOptionEnum::exit);
            break;
        }

        case InsertMenuOptionEnum::index:
        {
            fflush(stdin);
            unsigned int index;
            cout << "What index do you want to insert the Person in (min: 0, max: " << this->list()->size() << "):" << endl;
            cin >> index;
            fflush(stdin);

            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            this->list()->insert(person, index);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
            std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;

            printAllData();
            this->menu()->insertOption(InsertMenuOptionEnum::exit);
            break;
        }

        case InsertMenuOptionEnum::invalid:
            cout << "Invalid option." << endl;

            break;
        }
    }

    this->menu()->insertOption(InsertMenuOptionEnum::invalid);
}
void Header::Program::LinkedListProgram::executeRemoveMenu()
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
        {
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            this->list()->remove(0);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
            std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;

            printAllData();
            this->menu()->removeOption(RemoveMenuOptionEnum::exit);
            break;
        }

        case RemoveMenuOptionEnum::end:
        {
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            this->list()->remove();
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
            std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;

            printAllData();
            this->menu()->removeOption(RemoveMenuOptionEnum::exit);
            break;
        }

        case RemoveMenuOptionEnum::index:
        {
            fflush(stdin);
            unsigned int index;
            unsigned int maxSize = this->list()->size() != 0 ? this->list()->size() - 1 : 0;
            cout << "What index do you want to remove the Person from (min: 0, max: " << maxSize << "):" << endl;
            cin >> index;
            fflush(stdin);

            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            this->list()->remove(index);
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
            std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;

            printAllData();
            this->menu()->removeOption(RemoveMenuOptionEnum::exit);
            break;
        }

        case RemoveMenuOptionEnum::invalid:
            cout << "Invalid option." << endl;
            break;
        }
    }
    this->menu()->removeOption(RemoveMenuOptionEnum::invalid);
}
void Header::Program::LinkedListProgram::executeSearch()
{
    // fflush(stdin);
    // unsigned int index;
    // cout << "Enter an index to look into: (min: 0, max: " << this->list()->size() - 1 << "):" << endl;
    // cin >> index;
    // fflush(stdin);

    // std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    // if (index > this->list()->size() - 1)
    // {
    //     cout << "Invalid index" << endl;
    //     return;
    // }

    // Person person = this->list()->find(index)->element();
    // // TO DO: make an "isValid" method in "Person" class
    // if (person.getName() == "" || person.getRG() == "")
    // {
    //     cout << "Not found." << endl;
    //     return;
    // }

    // int c = 2;
    // int m = 1;
    // printPerson(person);
    // std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    // std::cout << "search at index: " << c << " conditions and " << m << " assignments" << std::endl;

    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;
    fflush(stdin);
    string rg;
    cout << "Enter a RG to look into: (min: 0, max: " << this->list()->size() - 1 << "):" << endl;
    cin >> rg;
    fflush(stdin);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Node<Person> *person = this->list()->find(Person("", rg));

    // TO DO: make an "isValid" method in "Person" class
    if (person->element().getName() == "" || person->element().getRG() == "")
    {
        cout << "Not found." << endl;
        return;
    }

    int c = 2;
    int m = 1;
    printPerson(person->element());
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "search at index: " << c << " conditions and " << m << " assignments" << std::endl;

    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;
}
void Header::Program::LinkedListProgram::executeSaveFile()
{
    fflush(stdin);
    string fileName;
    cout << "Enter what the file name is going to be:" << endl;
    getline(cin, fileName);

    this->fileManager()->fileName(fileName);
    List<string> *dataSet = new List<string>{};
    for (Node<Person> *iterator = this->list()->first();
         iterator != nullptr;
         iterator = iterator->next())
    {
        Person person = iterator->element();
        string data = person.getName() + ',' + person.getRG();
        dataSet->append(data);
    }

    this->fileManager()->writeData(dataSet);
}
void Header::Program::LinkedListProgram::executeLoadFile()
{
    fflush(stdin);
    string fileName;
    cout << "Enter the name of the file you want to extract data from:" << endl;
    getline(cin, fileName);

    this->fileManager()->fileName(fileName);
    List<string> dataSet = this->_fileManager->readData();
    for (Node<string> *iterator = dataSet.first();
         iterator != nullptr;
         iterator = iterator->next())
    {
        string data[2] = {"", ""};
        stringstream string_stream(iterator->element());
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
        this->list()->append(person);
    }
}

void Header::Program::LinkedListProgram::printAllData()
{
    if (this->list()->size() == 0)
        return;

    for (Node<Person> *iterator = this->list()->first();
         iterator != this->list()->last()->next();
         iterator = iterator->next())
    {
        printPerson(iterator->element());
    }
}
void Header::Program::LinkedListProgram::printAllDataFromFile()
{
    List<string> dataSet = this->_fileManager->readData();

    for (Node<string> *iterator = dataSet.first();
         iterator != nullptr;
         iterator = iterator->next())
    {
        string data[2] = {"", ""};
        stringstream string_stream(iterator->element());
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

Header::Model::Person Header::Program::LinkedListProgram::createPerson()
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
void Header::Program::LinkedListProgram::printPerson(const Person person)
{
    cout << "Name: " << person.getName()
         << " - RG: " << person.getRG()
         << endl;
}
#pragma endregion
