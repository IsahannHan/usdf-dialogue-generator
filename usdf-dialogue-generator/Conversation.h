#pragma once
#include <string>
#include <list>

#include "Page.h"

class Conversation {
public:
	std::string title = "CONVERSATION";

	std::string actor;
	std::list<Page> page;

	std::string tag(int nestedTabs);
	std::string baseTag();
};

