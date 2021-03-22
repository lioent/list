#pragma once

#include "Util/List.hpp"
#include <iostream>
#include <fstream>
#include <memory>

using std::ifstream;
using std::ofstream;
using std::string;
using std::unique_ptr;

using namespace Header::Util;

namespace Header::Manager
{
    class FileManager
    {
    public:
        FileManager(string fileName = "");
        ~FileManager();

#pragma region GET / SET
        string fileName() const
        {
            return this->_fileName;
        }
        void fileName(const string fileName) { this->_fileName = "Saves/" + fileName + ".txt"; }
#pragma endregion

#pragma region Actions
        List<string> readData();
        void writeData(List<string> *dataSet);
#pragma endregion

    private:
        string _fileName;
        ofstream _outputFileStream;
        ifstream _inputFileStream;
    };
}
