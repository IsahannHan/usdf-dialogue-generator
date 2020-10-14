#include <string>
#include <stdio.h>
#include <iostream>

namespace utils_creation_helper {

	enum ElementTypes { STRING, INTEGER, BOOL };

	std::string createElement(std::string element, ElementTypes elementType) {
		std::string elementValue;

		std::cout << "Please type the " << element << " attribute and press enter: ";

		switch (elementType) {
		case STRING:
			std::getline(std::cin >> std::ws, elementValue);
		case INTEGER:
			std::cin >> elementValue;
		case BOOL:
			char boolValue;

			while (true) {
				std::cin >> boolValue;
			
				if (toupper(boolValue) != 'Y' || toupper(boolValue) != 'Y') 
					std::cout << "Invalid boolean choice! Please type \"y\" or \"n\": ";
				else 
					break;
			}

			elementValue = toupper(boolValue) == 'Y' ? "true" : "false";
		}

		return elementValue;
	}

}