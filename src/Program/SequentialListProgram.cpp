#include "Program/SequentialListProgram.hpp"

using std::make_unique;

Header::Program::SequentialListProgram::SequentialListProgram() 
    : Header::Program::Program::Program()
{
    this->execute();
}

Header::Program::SequentialListProgram::~SequentialListProgram() 
{

}

#pragma region Actions
void Header::Program::SequentialListProgram::execute()
{
    this->_fileManager = make_unique<FileManager>("Data/NomeRG10.txt");
    this->_list = new SequentialList<Person>{};
}

void Header::Program::SequentialListProgram::close()
{
    delete(this->_list);
}


void Header::Program::SequentialListProgram::printAllData()
{
    //List<string> rawData = this->_fileManager.readData();
    List<string> dataSet = this->_fileManager->readData();
    std::cout << "test" << std::endl;
    // get raw data as list of strings and map it to the person class
    // then print it
}
#pragma endregion
