#include "../Manager/FileManager.hpp"
#include <memory>

using namespace Header_Manager;
using std::unique_ptr;


namespace Header_Program
{
    class Program
    {
    public:
        Program() {}
        ~Program() {}

#pragma region Actions
        virtual void execute() {}
        virtual void close() {}
#pragma endregion

    protected:
        unique_ptr<FileManager> _fileManager;
    };
}
