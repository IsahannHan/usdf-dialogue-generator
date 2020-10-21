#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>

#include "Element.h"
#include "ElementCreationHelper.h"

enum class ElementTypes { STRING, INTEGER, BOOL };

bool ElementCreationHelper::inputBoolean() {
	char b;

	while (true) {
		std::cin >> b;

		bool validYes = b == 'y' || b == 'Y';
		bool validNo = b == 'n' || b == 'N';

		if (!validYes && !validNo)
			std::cout << "Invalid boolean! Please type y/n (Yes/No): ";
		else
			return validYes ? true : false;
	}
}

// Input receivers

std::string ElementCreationHelper::createElementString(std::string element) {
	std::string elementValue;

	std::cout << "Please type the " << element << " attribute and press enter: ";

	std::getline(std::cin >> std::ws, elementValue);

	return elementValue;
}

bool ElementCreationHelper::createElementBoolean(std::string element) {
	std::cout << "Please type the " << element << " attribute and press enter: ";

	return inputBoolean();
}

int ElementCreationHelper::createElementInteger(std::string element) {
	return std::stoi(createElementString(element));
}

void ElementCreationHelper::creatingElementTitle(std::string title) {
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << "                         CREATING " << title << "                            " << std::endl;
	std::cout << "---------------------------------------------------------------------------" << std::endl;
}

bool ElementCreationHelper::satisfiedWithElement(Element element) {
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << "                         REVIEW " << element.title << "                      " << std::endl;
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << element.tag(0, true) << std::endl;

	std::cout << "Does this looks good? Y to continue, N to recreate: ";

	return inputBoolean();
}

bool ElementCreationHelper::anotherElementRequested(Element element, int index) {
	std::cout << "\"" << element.title << "\" element #" << index << " fully created!";
	std::cout << "Do you wish to create another \"" << element.title << "\"? Y for yes, N for no: ";

	return inputBoolean();
}
