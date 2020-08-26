#include "choice.h"

#include <string>
#include <stdio.h>

#define IDENTIFIER "page"

class Page
{
public:
    std::string name;
    std::string panel;
    std::string voice;
    std::string dialog;
    int drop;
    int link;

    Choice choices[10];

    std::string tag(int nestedTabs)
    {
        std::string tag;
        std::string initialTabs = generateInitialTabs(nestedTabs);
        std::string tabs = generateTabs(nestedTabs);

        tag.append(initialTabs.append(IDENTIFIER))
            .append(tagBracket(initialTabs, true))
            .append(createItemWithValue(tabs, GET_VARIABLE_NAME(name), name))
            .append(createItemWithValue(tabs, GET_VARIABLE_NAME(panel), panel))
            .append(createItemWithValue(tabs, GET_VARIABLE_NAME(voice), voice))
            .append(createItemWithValue(tabs, GET_VARIABLE_NAME(dialog), dialog))
            .append(createItemWithValue(tabs, GET_VARIABLE_NAME(drop), drop))
            .append(createItemWithValue(tabs, GET_VARIABLE_NAME(link), link))
            .append(tagBracket(initialTabs, false));

        return tag;
    }
};