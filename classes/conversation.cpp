#include "conversation.h"

using namespace std;

string Conversation::tag()
{
    const string open = "\n{\n";
    const string close = "\n{\n";
    const string tagidentifier = "conversation";
    string tag;

    tag.append(
        tagidentifier, open,
        
        actor,        
        
        close);

    return tag;
}