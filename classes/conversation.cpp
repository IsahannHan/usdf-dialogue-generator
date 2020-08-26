#include "../utils/functions.cpp"

#include "page.cpp"

#include <string>
#include <stdio.h>

#define IDENTIFIER "conversation"

class Conversation
{
public:
    std::string actor;
    Page page;

    std::string tag(int nestedTabs)
    {
        std::string tag;
        std::string initialTabs = generateInitialTabs(nestedTabs);
        std::string tabs = generateTabs(nestedTabs);

        tag.append(initialTabs.append(IDENTIFIER))
            .append(tagBracket(initialTabs, true))
            .append(createItemWithValue(tabs, GET_VARIABLE_NAME(actor), actor))
            .append(page.tag(nestedTabs))
            .append(tagBracket(initialTabs, false));

        return tag;
    }
};
