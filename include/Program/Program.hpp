#include "Manager/FileManager.hpp"
#include <memory>

using namespace Header::Manager;
using std::unique_ptr;

namespace Header::Program
{
    class Program
    {
    public:
        Program();
        ~Program();

#pragma region Actions
        virtual void execute() {}
        virtual void close() {}
#pragma endregion

    protected:
        unique_ptr<FileManager> _fileManager;
    };
}
