#pragma once
#include <string>
#include "Page.h"

class Conversation
{
public:
	Conversation(std::string actor, Page * page);

	std::string actor;
	Page* page;

	std::string tag(int nestedTabs);
};

