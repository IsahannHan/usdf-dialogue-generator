#pragma once
#include <string>
#include "Conversation.h"

class BaseFile
{
public:
	BaseFile(std::string nameSpace, std::string include, Conversation* conversation);

	std::string nameSpace;
	std::string include;
	Conversation* conversation;

	std::string tag();
};

