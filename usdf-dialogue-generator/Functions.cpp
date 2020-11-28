#include <string>
#include <stdio.h>
#include <sstream>
#include <list>
#include <iostream>

constexpr auto TAB = "\t";
constexpr auto ITEM_ASSIGN = " = ";

namespace utils_functions {

    const static std::string generateTabs(int& nestedTabs, bool baseTag)
    {
        if (baseTag)
            return "";

        std::string tabs;
        nestedTabs++;

        for (int i = 0; i < nestedTabs; i++)
        {
            tabs.append(TAB);
        }

        return tabs;
    }

    const static std::string generateInitialTabs(int& nestedTabs, bool baseTag)
    {
        int initialTabs = nestedTabs - 1;
        return generateTabs(initialTabs, baseTag);
    }

    const static std::string createItem(std::string tabs, std::string itemPrefix, std::string itemValue, bool quoted)
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

    const static std::string createItemWithValue(std::string tabs, std::string itemPrefix, bool itemValue)
    {
        return createItem(tabs, itemPrefix, itemValue ? "true" : "false", false);
    }

    const static std::string createItemWithValue(std::string tabs, std::string itemPrefix, std::string itemValue)
    {
        return createItem(tabs, itemPrefix, itemValue, true);
    }

    const static std::string createItemWithValue(std::string tabs, std::string itemPrefix, int itemValue)
    {
        std::string value = std::to_string(itemValue);

        return createItem(tabs, itemPrefix, value, false);
    }

    const static std::string tagBracket(std::string tabs, bool opening)
    {
        return opening ? "\n" + tabs.append("{") + "\n" : tabs.append("}") + "\n";
    }

}