#include "Program.hpp"
#include "Util/SequentialList.hpp"
#include "Model/Person.hpp"

using namespace Header::Util;
using namespace Header::Model;

namespace Header::Program
{
    class SequentialListProgram : public Program
    {
    public:
        SequentialListProgram();
        ~SequentialListProgram();

#pragma region Actions

        void execute();
        void close();

        void printAllData();

#pragma endregion

    private:
        SequentialList<Person> *_list;
    };
}
