#include "Ifitem.h"

#include "Functions.cpp"
#include "Generics.cpp"

#define GET_VARIABLE_NAME(v) (#v)

using namespace utils_functions;

constexpr auto IDENTIFIER = "ifitem";

std::string Ifitem::tag(int nestedTabs)
{
	std::string tag;
	std::string initialTabs = generateInitialTabs(nestedTabs);
	std::string tabs = generateTabs(nestedTabs);

	tag.append(initialTabs + IDENTIFIER)
		.append(tagBracket(initialTabs, true))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(item), item))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(amount), amount))
		.append(tagBracket(initialTabs, false));

	return tag;
}

std::string Ifitem::baseTag() {
	std::string tag;
	std::string tabs = "";

	tag.append(createItemWithValue(tabs, GET_VARIABLE_NAME(item), item))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(amount), amount));

	return tag;
}
