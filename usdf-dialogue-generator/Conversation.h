#pragma once
#include <string>
#include <list>

#include "Page.h"

class Conversation : public Element
{
public:
	Conversation(std::string actor, std::list<Page>* page);
	Conversation();

	std::string actor;
	std::list<Page>* page;

	std::string title = "CONVERSATION";

	std::string tag(int nestedTabs, bool baseTag);
};

