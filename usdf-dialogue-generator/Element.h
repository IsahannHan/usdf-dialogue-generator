#pragma once
#include <string>

class Element
{
public:
	std::string title;

	std::string tag(int nestedTabs, bool baseTag);

};

