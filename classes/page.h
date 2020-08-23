#include "choice.h"

using namespace std;

class Page {
    public:
        const string _identifier = "page";

        string name;
        string panel;
        string voice;
        string dialog;
        int drop;
        int link;

        Choice choices[10];
};