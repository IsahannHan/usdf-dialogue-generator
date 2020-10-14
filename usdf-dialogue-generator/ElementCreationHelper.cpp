#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>

#include "Element.h"

namespace utils_element_creation_helper {

	enum class ElementTypes { STRING, INTEGER, BOOL };

	std::string createElement(std::string element, ElementTypes elementType) {
		std::string elementValue;

		std::cout << "Please type the " << element << " attribute and press enter: ";

		switch (elementType) {
		case ElementTypes::STRING:
			std::getline(std::cin >> std::ws, elementValue);
		case ElementTypes::INTEGER:
			std::cin >> elementValue;
		case ElementTypes::BOOL:
			elementValue = boolToString(inputBoolean());
		}

		return elementValue;
	}

	void creatingElementTitle(Element::Elements title) {
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

	std::string boolToString(bool b) {
		return b ? "true" : "false";
	}

}