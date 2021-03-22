#pragma once

#include "Util/List.hpp"
#include <iostream>
#include <fstream>
#include <memory>

using std::string;
using std::ifstream;
using std::ofstream;
using std::unique_ptr;

using namespace Header::Util;

namespace Header::Manager
{
    class FileManager
    {
    public:
        FileManager(string fileName = "");
        ~FileManager();

#pragma region Actions
        List<string> readData();
        void writeData(string data);
#pragma endregion

    private:
        string _fileName;
        ofstream _outputFileStream;
        ifstream _inputFileStream;
    };
}
