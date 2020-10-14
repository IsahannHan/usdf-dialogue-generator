#pragma once
#include <string>
#include "Conversation.h"

class BaseFile : public Element
{
public:
	BaseFile(std::string nameSpace, std::string include, Conversation* conversation);
	BaseFile();

	Elements title = Elements::BASEFILE;

	std::string nameSpace;
	std::string include;

	Conversation* conversation;

	std::string tag(int nestedTabs, bool baseTag);
};

