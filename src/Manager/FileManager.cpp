#include "Manager/FileManager.hpp"

#include <iostream>

using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::make_unique;

Header::Manager::FileManager::FileManager(string fileName)
{
    this->fileName = fileName;
    if (this->fileName != "")
    {
        this->outputFileStream = make_unique<ofstream>(this->fileName);
        this->inputFileStream = make_unique<ifstream>(this->fileName);
    }
}

Header::Manager::FileManager::~FileManager()
{
}

#pragma region Actions
List<string> Header::Manager::FileManager::readData()
{
    List<string> dataSet = List<string> {};
    if (this->inputFileStream->is_open())
    {
        string line;
        while (getline(*(this->inputFileStream), line))
        {
            //cout << line << '\n';
        }
        this->inputFileStream->close();
    }
    else
        cout << "Unable to open file" << endl;

    return dataSet;
}

void Header::Manager::FileManager::writeData(string data)
{
    if (this->outputFileStream->is_open())
    {
        *(this->outputFileStream) << data << '\n';
        this->outputFileStream->close();
    }
    else
        cout << "Unable to open file";
}
#pragma endregion
