#include "Program/SequentialListProgram.hpp"

using std::make_unique;

#pragma region Actions
void Header::Program::SequentialListProgram::execute()
{
    this->_fileManager = make_unique<FileManager>();
    this->_list = new SequentialList<Person>{};
}

void Header::Program::SequentialListProgram::close()
{
    delete(this->_list);
}


void Header::Program::SequentialListProgram::printAllData()
{
    //List<string> rawData = this->_fileManager.readData();
    this->_fileManager->readData();

    // get raw data as list of strings and map it to the person class
    // then print it
}
#pragma endregion
