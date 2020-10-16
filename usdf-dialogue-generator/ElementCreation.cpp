#include <string>
#include <stdio.h>
#include <iostream>
#include <sstream>

#include "ElementCreationHelper.cpp"

#include "Conversation.h"
#include "BaseFile.h"

using namespace utils_element_creation_helper;

namespace utils_element_creation {

	BaseFile baseFileCreation() {
		BaseFile _baseFile = BaseFile();

		do {
			creatingElementTitle(_baseFile.title);

			_baseFile.nameSpace = createElementString("NAMESPACE");
			_baseFile.include = createElementString("INCLUDE");

		} while (!satisfiedWithElement(_baseFile));

		proceedNestedElementCreation(_baseFile); // Next: CONVERSATION

		return _baseFile;
	}

	void conversationCreation(BaseFile& baseFile) {
		// Create conversation, and link it to the current baseFile

		Conversation _conversation = Conversation();

		do {
			creatingElementTitle(_conversation.title);

			_conversation.actor = createElementString("ACTOR");

		} while (!satisfiedWithElement(_conversation));

		proceedNestedElementCreation(_conversation); // Next: PAGE

		// Link to parent

		baseFile.conversation = &_conversation;
	}

	void pageCreation(Conversation& conversation) {
		// Create pages, and link it to the current conversation

		std::list<Page> _pagesList;
		Page _page;

		do {
			_page = Page();

			do {
				creatingElementTitle(_page.title);

				_page.name = createElementString("NAME");
				_page.panel = createElementString("PANEL");
				_page.voice = createElementString("VOICE");
				_page.dialog = createElementString("DIALOG");
				_page.drop = createElementInteger("DROP");
				_page.link = createElementInteger("LINK");

			} while (!satisfiedWithElement(_page));

			proceedNestedElementCreation(_page); // Next element: IFITEM and CHOICE 

			_pagesList.push_back(_page);

		} while (anotherElementRequested(_page, _pagesList.size()));

		conversation.page = &_pagesList;
	}

	void ifItemCreation(Page& page) {
		// Create ifitem, and link it to the current page

		Ifitem _ifItem = Ifitem();

		do {
			creatingElementTitle(_ifItem.title);

			_ifItem.item = createElementInteger("ITEM");
			_ifItem.amount = createElementInteger("AMOUNT");

		} while (!satisfiedWithElement(_ifItem));

		page.ifitem = &_ifItem;
	}

	void choiceCreation(Page& page) {

		std::list<Choice> _choicesList;
		Choice _choice;

		do {
			_choice = Choice();

			do {
				creatingElementTitle(_choice.title);

				_choice.text = createElementString("TEXT");
				_choice.displaycost = createElementBoolean("DISPLAYCOST");
				_choice.yesmessage = createElementString("YESMESSAGE");
				_choice.nomessage = createElementString("NOMESSAGE");
				_choice.log = createElementString("LOG");
				_choice.giveitem = createElementInteger("GIVEITEM");
				_choice.special = createElementInteger("SPECIAL");
				_choice.arg0 = createElementInteger("ARG0");
				_choice.arg1 = createElementInteger("ARG1");
				_choice.arg2 = createElementInteger("ARG2");
				_choice.arg3 = createElementInteger("ARG3");
				_choice.arg4 = createElementInteger("ARG4");
				_choice.nextpage = createElementInteger("NEXTPAGE");
				_choice.closedialog = createElementBoolean("CLOSEDIALOG");

			} while (!satisfiedWithElement(_choice));

			proceedNestedElementCreation(_choice); // Next element: COST 

			_choicesList.push_back(_choice);

		} while (anotherElementRequested(_choice, _choicesList.size()));

		page.choice = &_choicesList;
	}

	void costCreation(Choice& choice) {
		// Create cost, and link it to the current choice

		Cost _cost = Cost();

		do {
			creatingElementTitle(_cost.title);

			_cost.item = createElementInteger("ITEM");
			_cost.amount = createElementInteger("AMOUNT");

		} while (!satisfiedWithElement(_cost));

		choice.cost = &_cost;
	}

	// Utils

	void proceedNestedElementCreation(Element& currentElement) {

		std::cout << "\"" << currentElement.title << "\" created!";

		if (currentElement.title == "BASEFILE") {
			std::cout << "\n Proceeding to create " << "CONVERSATION" << " object..." << std::endl;
			conversationCreation(static_cast<BaseFile&>(currentElement));
		} else if (currentElement.title == "CONVERSATION") {
			std::cout << "\n Proceeding to create " << "PAGE" << " object..." << std::endl;
			pageCreation(static_cast<Conversation&>(currentElement));
		} else if (currentElement.title == "PAGE") {
			std::cout << "\n Proceeding to create " << "IFITEM" << " object..." << std::endl;
			ifItemCreation(static_cast<Page&>(currentElement));

			std::cout << "\n Proceeding to create " << "CHOICE" << " object..." << std::endl;
			choiceCreation(static_cast<Page&>(currentElement));
		} else if (currentElement.title == "CHOICE") {
			std::cout << "\n Proceeding to create " << "COST" << " object..." << std::endl;
			costCreation(static_cast<Choice&>(currentElement));
		}
	}
}
