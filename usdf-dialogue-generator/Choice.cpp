#include "Choice.h"

#include "Functions.cpp"
#include "Generics.cpp"

#define GET_VARIABLE_NAME(v) (#v)

using namespace utils_functions;

constexpr auto IDENTIFIER = "choice";

Choice::Choice(std::string text,
	Cost* cost,
	bool displaycost,
	std::string yesmessage,
	std::string nomessage,
	std::string log,
	int giveitem,
	int special,
	int arg0,
	int arg1,
	int arg2,
	int arg3,
	int arg4,
	int nextpage,
	bool closedialog) {
	this->text = text;
	this->cost = cost;
	this->displaycost = displaycost;
	this->yesmessage = yesmessage;
	this->nomessage = nomessage;
	this->log = log;
	this->giveitem = giveitem;
	this->special = special;
	this->arg0 = arg0;
	this->arg1 = arg1;
	this->arg2 = arg2;
	this->arg3 = arg3;
	this->arg4 = arg4;
	this->nextpage = nextpage;
	this->closedialog = closedialog;
}


Choice::Choice()
{
}

std::string Choice::tag(int nestedTabs, bool baseTag)
{
	std::string tag;
	std::string initialTabs = generateInitialTabs(nestedTabs, baseTag);
	std::string tabs = generateTabs(nestedTabs, baseTag);

	tag.append(baseTag ? "" : initialTabs.append(IDENTIFIER))
		.append(baseTag ? "" : tagBracket(initialTabs, true))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(text), text))
		.append(baseTag ? "" : createSingleItem(nestedTabs, *cost, baseTag))
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
		.append(baseTag ? "" : tagBracket(initialTabs, false));

	return tag;
}
