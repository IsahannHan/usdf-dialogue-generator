#include "Page.h"
#include <string>
#include "Functions.cpp"
using namespace utils_functions;

constexpr auto IDENTIFIER = "page";

Page::Page(std::string name, std::string panel, std::string voice, std::string dialog, int drop, int link)
{
	this->name = name;
	this->panel = panel;
	this->voice = voice;
	this->dialog = dialog;
	this->drop = drop;
	this->link = link;
}

std::string Page::tag(int nestedTabs)
{
    std::string tag;
    std::string initialTabs = generateInitialTabs(nestedTabs);
    std::string tabs = generateTabs(nestedTabs);

    tag.append(initialTabs.append(IDENTIFIER))
        .append(tagBracket(initialTabs, true))
        .append(createItemWithValue(tabs, getVariableName(name), name))
        .append(createItemWithValue(tabs, getVariableName(panel), panel))
        .append(createItemWithValue(tabs, getVariableName(voice), voice))
        .append(createItemWithValue(tabs, getVariableName(dialog), dialog))
        .append(createItemWithValue(tabs, getVariableName(drop), drop))
        .append(createItemWithValue(tabs, getVariableName(link), link))
        .append(tagBracket(initialTabs, false));

    return tag;
}
