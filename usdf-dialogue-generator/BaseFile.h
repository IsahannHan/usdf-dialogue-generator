#pragma once
#include <string>
#include "Conversation.h"

class BaseFile {
public:
	std::string nameSpace;
	std::string title = "BASEFILE";

	std::string include;
	Conversation conversation;

	std::string tag(int nestedTabs);
	std::string baseTag();
};

