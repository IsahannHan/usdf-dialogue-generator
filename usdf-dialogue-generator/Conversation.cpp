#include <iostream>
#include <list>

#include "Conversation.h"
#include "Functions.cpp"
#include "Generics.cpp"

#define GET_VARIABLE_NAME(v) (#v)

using namespace utils_functions;

constexpr auto IDENTIFIER = "conversation";

std::string Conversation::tag(int nestedTabs) {
	std::string tag;
	std::string initialTabs = generateInitialTabs(nestedTabs);
	std::string tabs = generateTabs(nestedTabs);

	tag.append(initialTabs + IDENTIFIER)
		.append(tagBracket(initialTabs, true))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(actor), actor))
		.append(createMultipleItems(nestedTabs, page))
		.append(tagBracket(initialTabs, false));

	return tag;
}

std::string Conversation::baseTag() {
	std::string tag;
	std::string tabs = "";

	tag.append(createItemWithValue(tabs, GET_VARIABLE_NAME(actor), actor));

	return tag;
}


