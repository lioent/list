#include <iostream>
#include <fstream>
#include <memory>

#include "../util/List.hpp"

using std::ifstream;
using std::ofstream;
using std::unique_ptr;

using namespace Header_Util;

namespace Header_Manager
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
        string fileName;
        unique_ptr<ofstream> outputFileStream;
        unique_ptr<ifstream> inputFileStream;
    };
}
