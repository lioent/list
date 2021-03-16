#include <string>
using std::string;

#include "BaseEntity.hpp"

namespace header_model
{
    class Person
    {
    public:
        Person() {}
        ~Person() {}

        /* ================== GET; SET; ================== */
        string getName() { return this->name; }
        void setName(string newName) { this->name = newName; }

        string getRG() { return this->RG; }
        void setRG(string newRG) { this->RG = newRG; }
        /* ===================== END ===================== */

        /* =================== Actions =================== */
        /* ===================== END ===================== */

        /* ============== Auxiliary Methods ============== */
        /* ===================== END ===================== */

    private:
        string name;
        string RG;
    };

} // namespace model_header