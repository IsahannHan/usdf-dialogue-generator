#include "Conversation.h"
#include <iostream>
#include "Functions.cpp"

using namespace utils_functions;

constexpr auto IDENTIFIER = "conversation";

Conversation::Conversation(std::string actor, Page* page)
{
	this->actor = actor;
	this->page = page;
}

std::string Conversation::tag(int nestedTabs)
{
	std::string tag;
	std::string initialTabs = generateInitialTabs(nestedTabs);
	std::string tabs = generateTabs(nestedTabs);

	tag.append(initialTabs.append(IDENTIFIER))
		.append(tagBracket(initialTabs, true))
		.append(createItemWithValue(tabs, getVariableName(actor), actor))
		.append(page->tag(nestedTabs))
		.append(tagBracket(initialTabs, false));

	return tag;
}
