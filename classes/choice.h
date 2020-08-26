#include "cost.h"
#include <string>

class Choice{
    public:
        const std::string _identifier = "choice";

        std::string text;
        Cost cost;
        bool displaycost;
        std::string yesmessage;
        std::string nomessage;
        std::string log;
        int giveitem;

        int special;

        int nextpage;
        bool closedialog;

};
