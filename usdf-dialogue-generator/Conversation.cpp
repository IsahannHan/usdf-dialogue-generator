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

std::string Conversation::tag(int nestedTabs, bool baseTag)
{
	std::string tag;
	std::string initialTabs = generateInitialTabs(nestedTabs);
	std::string tabs = generateTabs(nestedTabs);

	tag.append(baseTag ? "" : initialTabs.append(IDENTIFIER))
		.append(baseTag ? "" : tagBracket(initialTabs, true))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(actor), actor))
		.append(baseTag ? "" : createMultipleItems(nestedTabs, *page))
		.append(baseTag ? "" : tagBracket(initialTabs, false));

	return tag;
}


