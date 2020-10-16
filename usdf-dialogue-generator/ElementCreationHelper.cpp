#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>

#include "Element.h"

namespace utils_element_creation_helper {

	enum class ElementTypes { STRING, INTEGER, BOOL };

	bool createElementBoolean(std::string element) {
		std::cout << "Please type the " << element << " attribute and press enter: ";

		return inputBoolean();
	}

	int createElementInteger(std::string element) {
		return std::stoi(createElementString(element));
	}

	std::string createElementString(std::string element) {
		std::string elementValue;

		std::cout << "Please type the " << element << " attribute and press enter: ";

		std::getline(std::cin >> std::ws, elementValue);

		return elementValue;
	}

	void creatingElementTitle(std::string title) {
		std::cout << "---------------------------------------------------------------------------" << std::endl;
		std::cout << "                         CREATING "<< title <<"                            " << std::endl;
		std::cout << "---------------------------------------------------------------------------" << std::endl;
	}

	bool satisfiedWithElement(Element element) {
		std::cout << "---------------------------------------------------------------------------" << std::endl;
		std::cout << "                         REVIEW "<< element.title <<"                      " << std::endl;
		std::cout << "---------------------------------------------------------------------------" << std::endl;
		std::cout << element.tag(0, true) << std::endl;

		std::cout << "Does this looks good? Y to continue, N to recreate: ";

		return inputBoolean();
	}

	bool anotherElementRequested(Element element, int index) {
		std::cout << "\"" << element.title << "\" element #" << index << " fully created!";
		std::cout << "Do you wish to create another \"" << element.title << "\"? Y for yes, N for no: ";

		return inputBoolean();
	}

	/*
		Helping with booleans
	*/

	bool inputBoolean() {
		char b;

		while (true) {
			std::cin >> b;

			if (toupper(b) != 'Y' || toupper(b) != 'Y')
				std::cout << "Invalid boolean! Please type y/n (Yes/No): ";
			else
				break;
		}

		return toupper(b) == 'Y' ? true : false;
	}

}