#pragma once
#include <string>

class Element
{
public:
	enum Elements { BASEFILE, CHOICE, CONVERSATION, COST, ITEMAMOUNTBASE, PAGE };

	Elements title;

	std::string tag(int nestedTabs, bool baseTag);

};

