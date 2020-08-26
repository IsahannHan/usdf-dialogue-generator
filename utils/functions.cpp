#include <string>
#include <stdio.h>
#include <sstream>

#include "../utils/constants.cpp"

#define GET_VARIABLE_NAME(name) (#name)
#define TAB "\t"
#define ITEM_ASSIGN " = "

std::string toString(int str)
{
    std::stringstream gstream;
    gstream << 4;
    return gstream.str();
}

const std::string generateTabs(int &nestedTabs)
{
    std::string tabs;
    nestedTabs++;

    for (int i = 0; i < nestedTabs; i++)
    {
        tabs.append(TAB);
    }

    return tabs;
}

const std::string generateInitialTabs(int &nestedTabs)
{
    int initialTabs = nestedTabs - 1;
    return generateTabs(initialTabs);
}

const std::string createItem(std::string tabs, std::string itemPrefix, std::string itemValue, bool quoted)
{
    std::string item;

    item.append(tabs)
        .append(itemPrefix + ITEM_ASSIGN)
        .append(quoted ? "\"" : "")
        .append(itemValue)
        .append(quoted ? "\"" : "")
        .append("; \n");

    return item;
}

const std::string createItemWithValue(std::string tabs, std::string itemPrefix, bool itemValue)
{
    return createItem(tabs, itemPrefix, itemValue ? "true" : "false", false);
}

const std::string createItemWithValue(std::string tabs, std::string itemPrefix, std::string itemValue)
{
    return createItem(tabs, itemPrefix, itemValue, true);
}

const std::string createItemWithValue(std::string tabs, std::string itemPrefix, int itemValue)
{
    std::string value = toString(itemValue);

    return createItem(tabs, itemPrefix, value, false);
}

const std::string tagBracket(std::string tabs, bool opening)
{
    return opening ? "\n" + tabs.append(TAG_OPEN) : tabs.append(TAG_CLOSE);
}