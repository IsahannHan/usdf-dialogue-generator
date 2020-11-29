#pragma once
#include <string>

#include "BaseFile.h"

class ElementCreationHelper
{
public:
	static bool createElementBoolean(std::string element);

	static int createElementInteger(std::string element);

	static std::string createElementString(std::string element);

	static void creatingElementTitle(std::string title);

	static bool satisfiedWithElement(std::string title, std::string tag);

	static bool anotherElementRequested(std::string elementTitle, int index);
};