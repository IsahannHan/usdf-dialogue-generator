#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <algorithm>

#include "ElementCreationHelper.h"
#include "BaseFile.h"

bool inputBoolean() {
	char b;

	while (true) {
		std::cin >> b;

		bool validYes = b == 'y' || b == 'Y';
		bool validNo = b == 'n' || b == 'N';

		if (!validYes && !validNo)
			std::cout << ">>> INVALID VALUE! Please type Y or N (Yes/No): ";
		else
			return validYes ? true : false;
	}
}

bool checkValidNumber(const std::string& s) {
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

std::string createElementBase(std::string element) {
	std::string elementValue;

	std::getline(std::cin >> std::ws, elementValue);

	return elementValue;
}

// Input receivers

bool ElementCreationHelper::createElementBoolean(std::string element) {
	std::cout << "> Please type the " << element << " attribute and press enter [Y/N]: ";

	return inputBoolean();
}

int ElementCreationHelper::createElementInteger(std::string element) {
	std::cout << "> Please type the " << element << " attribute and press enter [NUMERIC VALUE]: ";

	std::string value;

	while (true) {
		value = createElementBase(element);

		if (!checkValidNumber(value))
			std::cout << ">>> INVALID VALUE! Please type in only numbers: ";
		else
			break;
	}

	return std::stoi(value);
}

std::string ElementCreationHelper::createElementString(std::string element) {
	std::cout << "> Please type the " << element << " attribute and press enter [TEXT]: ";

	return createElementBase(element);
}

void ElementCreationHelper::creatingElementTitle(std::string title) {
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << "                         CREATING " << title << "                            " << std::endl;
	std::cout << "---------------------------------------------------------------------------" << std::endl;
}

bool ElementCreationHelper::satisfiedWithElement(std::string title, std::string tag) {
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << "                         REVIEW " << title << "                      " << std::endl;
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << tag << std::endl;

	std::cout << "> Does this looks good? Y to continue, N to recreate: ";

	return inputBoolean();
}

bool ElementCreationHelper::anotherElementRequested(std::string elementTitle, int index) {
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << "          \"" << elementTitle << "\" ELEMENT #" << index << " CREATED!     " << std::endl;
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	std::cout << "> Do you wish to create another \"" << elementTitle << "\"? [Y/N]: ";

	return inputBoolean();
}
