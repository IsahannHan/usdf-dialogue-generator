#include "../utils/constants.cpp"
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
        std::string tabs = generateTabs(nestedTabs);

        tag.append(IDENTIFIER)
            .append(TAG_OPEN)
            .append(createItemWithValue(tabs, GET_VARIABLE_NAME(actor), actor))
            .append(tabs).append(page.tag(nestedTabs))
            .append(TAG_CLOSE);

        return tag;
    }
};
