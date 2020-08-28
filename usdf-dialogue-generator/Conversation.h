#pragma once
#include <string>
#include <list>

#include "Page.h"

class Conversation
{
public:
	Conversation(std::string actor, std::list<Page>* page);

	std::string actor;
	std::list<Page>* page;

	std::string tag(int nestedTabs);
};

