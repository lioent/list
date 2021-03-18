#include "Program.hpp"
#include "Util/SequentialList.hpp"
#include "Model/Person.hpp"

using namespace Header_Util;
using namespace Header_Model;

namespace Header_Program
{
    class SequentialListProgram : public Program
    {
    public:
        SequentialListProgram() : Program() {}
        ~SequentialListProgram() {}

#pragma region Actions

        void execute();
        void close();

        void printAllData();

#pragma endregion

    private:
        SequentialList<Person> *_list;
    };
}