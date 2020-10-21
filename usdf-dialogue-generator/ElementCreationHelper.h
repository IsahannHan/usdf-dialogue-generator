#pragma once
#include <string>

#include "Element.h"

class ElementCreationHelper
{
public:
	static bool inputBoolean();

	static bool createElementBoolean(std::string element);

	static int createElementInteger(std::string element);

	static std::string createElementString(std::string element);

	static void creatingElementTitle(std::string title);

	static bool satisfiedWithElement(Element element);

	static bool anotherElementRequested(Element element, int index);
};