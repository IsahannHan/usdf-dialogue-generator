#pragma once
#include <string>
#include "Conversation.h"
#include "Element.h"

class BaseFile : public Element
{
public:
	BaseFile(std::string nameSpace, std::string include, Conversation conversation);
	BaseFile();

	std::string title = "BASEFILE";

	std::string nameSpace;
	std::string include;

	Conversation conversation;

	std::string tag(int nestedTabs, bool baseTag);
};

