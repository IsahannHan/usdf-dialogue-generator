#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>

#include "ElementCreationHelper.cpp"

#include "Conversation.h"
#include "BaseFile.h"

using namespace utils_element_creation_helper;

namespace utils_element_creation {

    void baseFileCreation() {
        BaseFile _baseFile;

        do {
            creatingElementTitle(_baseFile.title);

            _baseFile.nameSpace = createElement("NAMESPACE", ElementTypes::STRING);
            _baseFile.include = createElement("INCLUDE", ElementTypes::STRING);

        } while (!satisfiedWithElement(_baseFile));

        proceedNextElementCreation(_baseFile);
    }

    void conversationCreation(Conversation& conversation) {
        // Create Conversation
        char satisfied{};

        while (toupper(satisfied) != 'Y') {
            std::cout << "---------------------------------------------------------------------------" << std::endl;
            std::cout << "|                         CREATING CONVERSATION                            |" << std::endl;
            std::cout << "---------------------------------------------------------------------------" << std::endl;
            std::cout << "Please type the \"ACTOR\" attribute and press enter: ";
            std::getline(std::cin >> std::ws, conversation.actor);

            std::cout << "---------------------------------------------------------------------------" << std::endl;
            std::cout << "|                         REVIEW CONVERSATION                             |" << std::endl;
            std::cout << "---------------------------------------------------------------------------" << std::endl;
            std::cout << conversation.tag(0, true) << std::endl;

            std::cout << "Does this looks good? Y to continue, N to recreate: ";
            std::cin >> satisfied;

            system("cls");
        }

        std::cout << "\"CONVERSATION\" created!";
        std::cout << "\n Proceeding to create \"PAGE\" objects..." << std::endl;

        system("pause");

        pageCreation(conversation);
    }

    // 

    void proceedNextElementCreation(Element& currentElement) {
        std::cout << "\"" << currentElement.title << "\" created!";
        std::cout << "\n Proceeding to create \"CONVERSATION\" object..." << std::endl;

        //system("pause");

        switch (currentElement.title) {
        case Element::Elements::BASEFILE:
            conversationCreation(dynamic_cast<Conversation*>(currentElement));
        }
    }

}