#include "Program/Program.hpp"

using std::make_unique;

Header::Program::Program::Program()
{
    this->_fileManager = make_unique<FileManager>();
}

Header::Program::Program::~Program()
{
}
