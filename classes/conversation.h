#include "page.h"

using namespace std;

class Conversation{
    public:
        const string _identifier = "conversation";

        string actor;
        Page page;

        string tag();
};