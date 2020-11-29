#include "Ifitem.h"

#include "Functions.cpp"
#include "Generics.cpp"

#define GET_VARIABLE_NAME(v) (#v)

using namespace utils_functions;

constexpr auto IDENTIFIER = "ifitem";

Ifitem::Ifitem()
{
}

std::string Ifitem::tag(int nestedTabs, bool baseTag)
{
	std::string tag;
	std::string initialTabs = generateInitialTabs(nestedTabs, baseTag);
	std::string tabs = generateTabs(nestedTabs, baseTag);

	tag.append( baseTag ? "" : initialTabs + IDENTIFIER)
		.append(baseTag ? "" : tagBracket(initialTabs, true))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(item), item))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(amount), amount))
		.append(baseTag ? "" : tagBracket(initialTabs, false));

	return tag;
}
