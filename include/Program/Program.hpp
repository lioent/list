#pragma once

#include "Manager/FileManager.hpp"

using namespace Header::Manager;

namespace Header::Program
{
    class Program
    {
    public:
        Program();
        ~Program();

#pragma region GET / SET
        FileManager *fileManager() const { return this ->_fileManager; }
#pragma endregion

#pragma region Actions
        virtual void execute() {}
        virtual void close() {}

    protected:
        void waitForInput();
#pragma endregion

    protected:
        FileManager *_fileManager;
    };
}
