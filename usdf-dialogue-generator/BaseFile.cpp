#include "BaseFile.h"
#include "Functions.cpp"
#include "Generics.cpp"

#define GET_VARIABLE_NAME(v) (#v)

int INITIAL_TABS = 0;

using namespace utils_functions;

std::string BaseFile::tag(int nestedTabs)
{
	std::string tag;
	std::string initialTabs = generateInitialTabs(INITIAL_TABS);

	tag.append(createItemWithValue(initialTabs, "namespace", nameSpace)) // Can't create variable with name 'namespace', so just send it like this lmao
	    .append(createItemWithValue(initialTabs, GET_VARIABLE_NAME(include), include))
		.append("\n")
		.append(createSingleItem(INITIAL_TABS, conversation));

	return tag;
}

std::string BaseFile::baseTag() {
	std::string baseTag;
	std::string tabs = "";

	baseTag.append(createItemWithValue(tabs, "namespace", nameSpace))
		.append(createItemWithValue(tabs, GET_VARIABLE_NAME(include), include));

	return baseTag;
}