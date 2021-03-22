#include "Program/SequentialListProgram.hpp"
#include <sstream>
#include <chrono>

using namespace Header::Menu::Enum;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::stringstream;

Header::Program::SequentialListProgram::SequentialListProgram()
    : Header::Program::Program::Program()
{
    this->_list = nullptr;
    this->_sequentialListMenu = nullptr;
}
Header::Program::SequentialListProgram::~SequentialListProgram()
{
    delete (this->_list);
    delete (this->_sequentialListMenu);
}

#pragma region Actions
void Header::Program::SequentialListProgram::execute()
{
    this->_fileManager = new FileManager("Data/NomeRG10.txt");
    this->_list = new SequentialList<Person>{};
    this->_sequentialListMenu = new SequentialListMenu();

    executeMainMenu();
}
void Header::Program::SequentialListProgram::close()
{
    delete (this->_list);
    delete (this->_sequentialListMenu);
}
#pragma endregion

#pragma region Auxiliary Methods
void Header::Program::SequentialListProgram::executeMainMenu()
{
    while (this->menu()->option() != MenuOptionEnum::exit)
    {
        fflush(stdin);
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
            std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
            this->list()->insert(person, 0);
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
            this->list()->insert(person, this->list()->size());
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
            cout << "What index do you want to remove the Person from (min: 0, max: " << maxSize << "):";
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
void Header::Program::SequentialListProgram::executeSearch()
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

    // Person person = this->list()->findAtIndex(index);
    // // TO DO: make an "isValid" method in "Person" class
    // if (person.getName() == "" || person.getRG() == "")
    // {
    //     cout << "Not found." << endl;
    //     return;
    // }

    // int c = 2;
    // int m = 1;
    // std::cout << "remove at index: " << c << " conditions and " << m << " assignments" << std::endl;

    // printPerson(person);

    // std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    // std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;
    fflush(stdin);
    string rg;
    cout << "Enter a RG to look into:" << endl;
    cin >> rg;
    fflush(stdin);

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Person person = this->list()->find(Person("", rg));
    // TO DO: make an "isValid" method in "Person" class
    if (person.getName() == "" || person.getRG() == "")
    {
        cout << "Not found." << endl;
        return;
    }

    int c = 2;
    int m = 1;
    std::cout << "search by rg: " << c << " conditions and " << m << " assignments" << std::endl;

    printPerson(person);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;
}
void Header::Program::SequentialListProgram::executeSaveFile()
{
    fflush(stdin);
    string fileName;
    cout << "Enter what the file name is going to be:" << endl;
    getline(cin, fileName);

    this->fileManager()->fileName(fileName);
    List<string> *dataSet = new List<string>{};
    for (unsigned int index = 0;
         index < this->list()->size();
         index++)
    {
        Person person = this->list(index);
        string data = person.getName() + ',' + person.getRG();
        dataSet->append(data);
    }

    this->fileManager()->writeData(dataSet);
}
void Header::Program::SequentialListProgram::executeLoadFile()
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
        this->list()->insert(person, this->list()->size());
    }
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
