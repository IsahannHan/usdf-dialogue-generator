#include <string>
#include <stdio.h>

#define GET_VARIABLE_NAME(name) (#name)

const std::string tab = "\t";

const std::string generateTabs(int &nestedTabs)
{
    std::string tabs;
    nestedTabs++;

    for (int i = 0; i < nestedTabs; i++)
    {
        tabs.append(tab);
    }

    return tabs;
}

const std::string createItemWithValue(std::string tabs, std::string itemPrefix, std::string itemValue)
{
    std::string item;

    item.append(tabs)
        .append(itemPrefix)
        .append("\"").append(itemValue).append("\"")
        .append("; \n");

    return item;
}