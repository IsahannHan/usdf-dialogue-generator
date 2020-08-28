#include <string>
#include <list>

#include "Page.h"
#include "Functions.cpp"
#include "Generics.cpp"

#define GET_VARIABLE_NAME(v) (#v)

using namespace utils_functions;

constexpr auto IDENTIFIER = "page";

Page::Page(std::string name, std::string panel, std::string voice, std::string dialog, int drop, int link, Ifitem* ifitem, std::list<Choice>* choice)
{
	this->name = name;
	this->panel = panel;
	this->voice = voice;
	this->dialog = dialog;
	this->drop = drop;
	this->link = link;
	this->ifitem = ifitem;
	this->choice = choice;
}

std::string Page::tag(int nestedTabs)
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
		.append(createSingleItem(nestedTabs, *ifitem))
		.append(createMultipleItems(nestedTabs, *choice))
		.append(tagBracket(initialTabs, false));

	return tag;
}

