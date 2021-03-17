#include "Menu.hpp"
#include "Person.hpp"
#include "SequentialList.hpp"

using namespace Header_Model;
using namespace Header_Util;

namespace Header_Manager
{
    class SequentialListMenu
    {
    public:
        SequentialListMenu();
        ~SequentialListMenu() {}

        void openMenu();
        void exitMenu();

    private:

        SequentialList<Person>* _list;
    };
}
