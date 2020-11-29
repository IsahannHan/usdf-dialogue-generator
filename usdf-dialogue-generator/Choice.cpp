#include "Choice.h"

#include "Functions.cpp"
#include "Generics.cpp"

#define GET_VARIABLE_NAME(v) (#v)

using namespace utils_functions;

constexpr auto IDENTIFIER = "choice";

std::string Choice::tag(int nestedTabs)
{
	std::string tag;
	std::string initialTabs = generateInitialTabs(nestedTabs);
	std::string tabs = generateTabs(nestedTabs);

	tag.append(initialTabs.append(IDENTIFIER))
		.append(tagBracket(initialTabs, true))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(text), text))
		.append(createSingleItem(nestedTabs, cost))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(displaycost), displaycost))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(yesmessage), yesmessage))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(nomessage), nomessage))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(log), log))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(giveitem), giveitem))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(special), special))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(arg0), arg0))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(arg1), arg1))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(arg2), arg2))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(arg3), arg3))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(arg4), arg4))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(nextpage), nextpage))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(closedialog), closedialog))
		.append(tagBracket(initialTabs, false));

	return tag;
}

std::string Choice::baseTag() {
	std::string tag;
	std::string tabs = "";

	tag.append(createItemWithValue(tabs, GET_VARIABLE_NAME(text), text))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(displaycost), displaycost))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(yesmessage), yesmessage))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(nomessage), nomessage))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(log), log))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(giveitem), giveitem))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(special), special))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(arg0), arg0))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(arg1), arg1))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(arg2), arg2))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(arg3), arg3))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(arg4), arg4))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(nextpage), nextpage))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(closedialog), closedialog));

	return tag;
}