#include "Manager/FileManager.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::getline;
using std::make_unique;
using std::string;

Header::Manager::FileManager::FileManager(string fileName)
{
    this->_fileName = fileName;
}

Header::Manager::FileManager::~FileManager()
{
}

#pragma region Actions
List<string> Header::Manager::FileManager::readData()
{
    List<string> dataSet = List<string>{};
    this->_inputFileStream.open(this->_fileName);
    if (this->_inputFileStream.is_open())
    {
        string line;
        while (this->_inputFileStream.good())
        {
            getline(this->_inputFileStream, line);
            if(line != "")
                dataSet.insert(line);
            //cout << line << '\n';
        }
        this->_inputFileStream.close();
    }
    else
        cout << "Unable to open file" << endl;

    return dataSet;
}

void Header::Manager::FileManager::writeData(string data)
{
    this->_outputFileStream.open(this->_fileName);
    if (this->_outputFileStream.is_open())
    {
        this->_outputFileStream << data << '\n';
        this->_outputFileStream.close();
    }
    else
        cout << "Unable to open file";
}
#pragma endregion
