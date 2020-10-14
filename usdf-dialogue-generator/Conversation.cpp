#include <iostream>
#include <list>

#include "Conversation.h"
#include "Functions.cpp"
#include "Generics.cpp"

#define GET_VARIABLE_NAME(v) (#v)

using namespace utils_functions;

constexpr auto IDENTIFIER = "conversation";

Conversation::Conversation(std::string actor, std::list<Page>* page)
{
	this->actor = actor;
	this->page = page;
}

Conversation::Conversation()
{
}

std::string Conversation::tag(int nestedTabs, bool baseTag)
{
	std::string tag;
	std::string initialTabs = generateInitialTabs(nestedTabs);
	std::string tabs = generateTabs(nestedTabs);

	tag.append(initialTabs.append(IDENTIFIER))
		.append(tagBracket(initialTabs, true))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(actor), actor))
		.append(createMultipleItems(nestedTabs, *page, baseTag))
		.append(tagBracket(initialTabs, false));

	return tag;
}


