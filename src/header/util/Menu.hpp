#include <stdlib.h>
#include <iostream>

#include "../model/Person.hpp"

using std::cin;
using std::cout;
using std::endl;

using namespace header_model;

namespace header_util
{
    class Menu
    {
    public:
        Menu() { OpenListTypeMenu(); }
        ~Menu() { TerminateProgram(); }

        /* ================== GET; SET; ================== */
        /* ===================== END ===================== */

        /* =================== Actions =================== */
        void OpenListTypeMenu()
        {
            char option = ' ';
            while (option != '1' && option != '2')
            {
                cout << "Select a list type:" << endl;
                cout << "1. Sequential List" << endl;
                cout << "2. Linked List" << endl;
                cin >> option;

                switch (option)
                {
                case '1':
                    InitializeSequentialList();
                    break;

                case '2':
                    break;

                default:
                    cout << "Invalid option." << endl;
                    break;
                }
            }
        }

        void TerminateProgram()
        {
            cout << "Program terminated." << endl;
        }

        void InitializeSequentialList()
        {
            cout << "Not implemented." << endl;
        }

        void InitializeLinkedList()
        {
            cout << "Not implemented" << endl;
        }
        /* ===================== END ===================== */

        /* ============== Auxiliary Methods ============== */
        /* ===================== END ===================== */

    private:
    };
}