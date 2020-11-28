#include "BaseFile.h"
#include "Functions.cpp"
#include "Generics.cpp"

#define GET_VARIABLE_NAME(v) (#v)

int INITIAL_TABS = -1;

using namespace utils_functions;

BaseFile::BaseFile(std::string nameSpace, std::string include, Conversation* conversation)
{
	this->nameSpace = nameSpace;
	this->include = include;
	this->conversation = conversation;
}

BaseFile::BaseFile()
{
}

std::string BaseFile::tag(int nestedTabs, bool baseTag)
{
	std::string tag;
	std::string initialTabs = generateInitialTabs(INITIAL_TABS, baseTag);

	tag.append(createItemWithValue(initialTabs, "namespace", nameSpace)) // Can't create variable with name 'namespace', so just send it like this lmao
	    .append(createItemWithValue(initialTabs, GET_VARIABLE_NAME(include), include))
		.append("\n")
		.append(baseTag ? "" : createSingleItem(INITIAL_TABS, *conversation, baseTag));

	return tag;
}
