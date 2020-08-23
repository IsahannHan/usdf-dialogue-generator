#include "cost.h"

using namespace std;

class Choice{
    public:
        const string _identifier = "choice";
        
        string text;
        Cost cost;
        bool displaycost;
        string yesmessage;
        string nomessage;
        string log;
        int giveitem;

        int special;

        int nextpage;
        bool closedialog;

};
